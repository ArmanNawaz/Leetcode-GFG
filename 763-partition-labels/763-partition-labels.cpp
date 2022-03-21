class Solution {
public:
    vector<int> partitionLabels(string s) {
        return solve(s);
    }
private:
    vector<int> solve(string s) {
        vector<int> hashMap(26, 0);
        
        for(int i = 0; i < s.length(); ++i) 
            hashMap[s[i] - 'a'] = i;
        
        vector<int> ans;
        
        int start = 0, end = 0;
        
        for(int i = 0; i < s.length(); ++i) {
            end = max(end, hashMap[s[i] - 'a']);
            
            if(i == end) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};