class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26, false);
        
        for(char& ch: sentence) {
            seen[ch - 'a'] = true;
        }
        
        for(int i = 0; i < seen.size(); ++i) {
            if(seen[i] == false)
                return false;
        }
        return true;
    }
};