class Solution {
public:
    bool hasAllCodes(string s, int k) {
        return solve(s, k);
    }
private:
    bool solve(string s, int k) {
        int n = s.length();
        
        if(k > n)
            return false;
        
        unordered_set<string> set;
        for(int i = 0; i < n - k + 1; ++i) {
            set.insert(s.substr(i, k));
        }
        return set.size() == (1 << k);
    }
};