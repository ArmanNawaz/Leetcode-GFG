class Solution {
public:
    string getSmallestString(int n, int k) {
        return solve(n, k);
    }
private:
    string solve(int n, int k) {
        string ans(n, 'a');
        for(int i = n - 1; i > -1; --i) {
            if((k - i) > 26) {
                ans[i] = 'z';
                k = k - 26;
            }
            else {
                ans[i] = 'a' + k - i - 1;
                k = i;
            }
        }
        return ans;
    }
};