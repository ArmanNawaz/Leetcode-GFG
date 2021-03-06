// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        return solve1();
        // return solve();
    }
private:
    // Channa Sir
    // Recursive
    int solve() {
        int num = 7 * (rand7() - 1) + (rand7() - 1);
        
        if(num < 40)
            return (num % 10) + 1;
        
        return solve();
    }
    
    // Iterative
    int solve1() {
        while(true){
            int num = 7 * (rand7() - 1) + (rand7() - 1);

            if(num < 40)
                return (num % 10) + 1;
        }
    }
};