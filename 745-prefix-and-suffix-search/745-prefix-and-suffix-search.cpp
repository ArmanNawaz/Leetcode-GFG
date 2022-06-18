class WordFilter {    
    vector<string> getPrefixes(string s){
        string temp = "";
        vector<string> ans;
        for(int i = 0; i < s.length(); i++){
            temp += s[i];
            ans.push_back(temp);
        }
        return ans;
    }
    
    vector<string> getSuffixes(string s){
        string temp = "";
        vector<string> ans;
        for(int i = s.length() - 1; i >= 0; i--){
            temp = s[i] + temp;
            ans.push_back(temp);
        }
        return ans;
    }
public:
    unordered_map<string,int> mp;
    
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++){
            string s = words[i];
            for(auto x: getPrefixes(s))
                for(auto y: getSuffixes(s)){
                    mp[x + "-" + y] = i + 1;
                }
        }
    }
    
    int f(string p, string s) {
        return mp[p + "-" + s] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */