class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        return solve(time);
    }
private:
    int solve(vector<int>& time) {
        int ans = 0;
        vector<int> freq(60,0);
        
        for(int i = 0; i < time.size(); i++) {
            int x = time[i] % 60;
            if(x == 0)
                ans += freq[0];
            else
                ans += freq[60 - x];
            freq[x]++;
        }
        return ans;
    }
};