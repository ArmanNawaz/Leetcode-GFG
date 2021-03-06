class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return daily(s);
    }
private:
    int daily(string s) {
        unordered_map<char, int> hashMap;
        
        int wStart = 0;
        int maxLen = 0;
        
        for(int wEnd = 0; wEnd < s.length(); ++wEnd) {
            if(hashMap.find(s[wEnd]) != hashMap.end())
                wStart = max(wStart, hashMap[s[wEnd]] + 1);
            hashMap[s[wEnd]] = wEnd;
            maxLen = max(maxLen, wEnd - wStart + 1);
        }
        return maxLen;
    }
};