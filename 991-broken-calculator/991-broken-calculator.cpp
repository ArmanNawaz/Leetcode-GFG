class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // return 1;
        return solve(startValue, target);
    }
private:
    int solve(int startValue, int target) {
        int count = 0;
        while(target != startValue) {
            if(target < startValue){
                count += startValue - target;
                return count;
            }
            
            else if(target + 1 == startValue)
                target += 1;
            
            else if(target % 2 == 0)
                target /= 2;
            else
                ++target;
            ++count;
        }
        return count;
    }
};