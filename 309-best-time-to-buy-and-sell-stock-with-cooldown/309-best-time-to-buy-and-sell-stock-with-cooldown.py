class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        bsp = -1 * prices[0]
        ssp, csp = 0, 0
        
        for i in range(1, len(prices)):
            
            nbsp = max(bsp, csp - prices[i])
            nssp = max(ssp, bsp + prices[i])
            ncsp = max(csp, ssp)
            
            bsp, ssp, csp = nbsp, nssp, ncsp
        
        return ssp
        