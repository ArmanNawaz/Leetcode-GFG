class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
private:
    int solve(vector<int>& prices) {
        int bsp = -1 * prices[0], ssp = 0, csp = 0;
        
        for(int i = 1; i < prices.size(); ++i) {
            
            int nbsp = max(bsp, csp - prices[i]);
            int nssp = max(ssp, bsp + prices[i]);
            int ncsp = max(csp, ssp);
            
            bsp = nbsp;
            ssp = nssp;
            csp = ncsp;
        }
        return ssp;
    }
};