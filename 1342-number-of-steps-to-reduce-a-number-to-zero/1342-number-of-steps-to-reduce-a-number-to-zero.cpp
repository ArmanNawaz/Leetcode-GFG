class Solution {
public:
    int numberOfSteps(int num) {
        return solve(num);
    }
private:
    int solve(int num) {
        int count = 0;
        
        while(num) {
            if((num & 1) == 0)
                num /= 2;
            else
                --num;
            ++count;
        }
        return count;
    }
};