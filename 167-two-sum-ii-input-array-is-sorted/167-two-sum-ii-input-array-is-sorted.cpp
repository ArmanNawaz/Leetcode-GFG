class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        return solve(numbers, target);
    }
private:
    vector<int> solve(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            
            if(sum < target) ++i;
            else if(sum > target) --j;
            else break;
        }
        return {i + 1, j + 1};
    }
};