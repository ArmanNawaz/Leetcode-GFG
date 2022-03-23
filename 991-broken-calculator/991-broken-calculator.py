class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        count = 0
        while target != startValue:
            
            if target < startValue:
                count += startValue - target
                return count
            
            
            elif target + 1 == startValue:
                target += 1
            
            elif target % 2 == 0:
                target //= 2
                
            else:
                target += 1
            count += 1
        
        return count