class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        bsp = -1 * prices[0]
        ssp = 0
        
        for i in range(1, len(prices)):
            nbsp = max(bsp, ssp - prices[i])
            nssp = max(ssp, bsp + prices[i] - fee)
            
            bsp, ssp = nbsp, nssp
            
        return ssp