class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return solve1(s);
    }
private:
    int solve1(string s) {
        unordered_map<char, int> hashMap;
        int wStart = 0, wEnd;
        int maxLen = 0;
        
        for(wEnd = 0; wEnd < s.size(); ++wEnd) {
            if(hashMap.find(s[wEnd]) != hashMap.end()) {
                wStart = max(wStart, hashMap[s[wEnd]] + 1);
            }
            hashMap[s[wEnd]] = wEnd;
            maxLen = max(maxLen, wEnd - wStart + 1);
        }
        return maxLen;
    }
    
    int solve(string s){
        unordered_map<char, int> hashMap;
        int wStart = 0, wEnd, n = s.size();
        int maxLength = 0;
        for(wEnd = 0; wEnd < n; wEnd++){
            if(hashMap.find(s[wEnd]) != hashMap.end()){
                wStart = max(wStart, hashMap[s[wEnd]] + 1);
            }
            maxLength = max(maxLength, wEnd - wStart + 1);
            hashMap[s[wEnd]] = wEnd;
        }
        return maxLength;
    }
};