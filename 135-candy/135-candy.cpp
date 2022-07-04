class Solution {
public:
    int candy(vector<int>& ratings) {
        return daily(ratings);
    }
private:
    int daily(vector<int>& ratings) {
        vector<int> ans;
        ans.push_back(1);
        
        int n = ratings.size();
        
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i - 1])
                ans.push_back(ans.back() + 1);
            else
                ans.push_back(1);
        }
        
        for(int i = n - 1; i > 0; --i) {
            if(ratings[i - 1] > ratings[i] && ans[i] >= ans[i - 1])
                ans[i - 1] = ans[i] + 1;
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
    } 
};