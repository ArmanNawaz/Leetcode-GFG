class Solution {
public:
    string removeDuplicates(string s, int k) {
        return solve(s, k);
    }
private: 
    string solve(string s, int k) {
        int i = 0, n = s.length();
        vector<int> count(n);
        
        for (int j = 0; j < n; ++j) {
            s[i] = s[j];
            
            count[i] = 1;
            if(i > 0 && s[i - 1] == s[i]) {
                count[i] += count[i - 1];
            }
            
            if (count[i] == k) 
                i -= k;
            ++i;
        }
        return s.substr(0, i);
    }
};