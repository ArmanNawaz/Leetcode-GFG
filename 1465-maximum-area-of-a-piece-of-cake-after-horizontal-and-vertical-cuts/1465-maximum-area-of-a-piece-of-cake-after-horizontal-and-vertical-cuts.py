class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.extend([0, h])
        verticalCuts.extend([0, w])
        
        horizontalCuts.sort()
        verticalCuts.sort()
        
        l, b = 0, 0
        
        for i in range(1, len(horizontalCuts)):
            l = max(l, horizontalCuts[i] - horizontalCuts[i - 1])
        
        for i in range(1, len(verticalCuts)):
            b = max(b, verticalCuts[i] - verticalCuts[i - 1])
        
        return (l * b) % int(1e9 + 7)