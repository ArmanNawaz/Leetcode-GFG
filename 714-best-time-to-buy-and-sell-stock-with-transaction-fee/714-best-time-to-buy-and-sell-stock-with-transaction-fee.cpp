class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
private:
    int solve(vector<int>& prices, int fee) {
        int bsp = -1 * prices[0];
        int ssp = 0;
        
        for(int i = 1; i < prices.size(); ++i) {
            int nbsp, nssp;
            nbsp = max(bsp, ssp - prices[i]);
            nssp = max(ssp, bsp + prices[i] - fee);
            
            bsp = nbsp;
            ssp = nssp;
        }
        return ssp;
    }
};
