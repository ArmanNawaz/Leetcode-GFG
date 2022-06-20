class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        return daily(words);
    }
private:
    int daily(vector<string>& words) {
        unordered_set<string> mySet(words.begin(), words.end());
        
        for(auto word: words) {
            for(int i = 1; i < word.length(); ++i) 
                mySet.erase(word.substr(i));
        }
        int ans = 0;
        
        for(string word: mySet)
            ans += word.length() + 1;
        return ans;
    }
};