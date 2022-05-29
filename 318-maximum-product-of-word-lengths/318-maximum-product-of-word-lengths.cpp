class Solution {
public:
    int maxProduct(vector<string>& words) {
        return solve(words);
    }
private:
    // daily
    bool helper(unordered_set<char>& s1, unordered_set<char>& s2) {
        for(auto ch: s1) {
            if(s2.find(ch) != s2.end())
                return false;
        }
        return true;
    }
    int solve(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<unordered_set<char>> s(n);
        
        for(int i = 0; i < n; ++i) {
            
            for(char ch: words[i])
                s[i].insert(ch);
            for(int j = 0; j < i; ++j) {
                if(helper(s[i], s[j]))
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
            }
        } 
        return ans;
    }
};