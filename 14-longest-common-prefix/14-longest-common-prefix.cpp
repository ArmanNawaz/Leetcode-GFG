class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return solve(strs);
    }
private:
    // O(nlogn) Time and O(1) extra space
    string solve(vector<string>& strs) {
        int n = strs.size();
        
        sort(strs.begin(), strs.end());
        
        string ans = "";
        for(int i = 0; i < strs[0].size(); ++i) {
            if(strs[0][i] == strs[n - 1][i])
                ans += strs[0][i];
            else
                break;
        }
        return ans;
    }
};