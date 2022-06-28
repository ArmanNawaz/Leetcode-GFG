class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> hashMap;
        
        for(char n: num) {
            hashMap[n - '0']++;
        }
        
        for(int i = 0; i < num.length(); ++i) {
            if(hashMap[i] != (num[i] - '0'))
                return false;
        }
        return true;
    }
};