class Solution {
public:
    string reverseWords(string s) {
        // daily
        string tmp = "";
        vector<string> words;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == ' ' || i == s.length() - 1) {
                if(i == s.length() - 1)
                    tmp += s[i];
                words.push_back(tmp);
                tmp = "";
            } else
                tmp += s[i];
        }
        string ans = "";
        
        for(string each: words) {
            reverse(each.begin(), each.end());
            each += " ";
            ans += each;
        }
        ans.pop_back();
        return ans;
    }
};