class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        if k == len(cardPoints):
            return sum(cardPoints)
        
        points = sum(cardPoints[: k])
        
        maxPoints = points
        end = len(cardPoints) - 1
        
        for i in range(k - 1, -1, -1):
            points -= cardPoints[i]
            points += cardPoints[end]
            
            end -= 1
            maxPoints = max(maxPoints, points)
        return maxPoints