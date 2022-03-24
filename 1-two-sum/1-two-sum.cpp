class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        visited[nums[0]] = 0;
        
        for(int j = 1; j < nums.size(); j++){
            if(visited.find(target - nums[j]) != visited.end())
                return {visited[target - nums[j]], j};
            visited[nums[j]] = j;    
        }
        return {-1, -1};
    }
};