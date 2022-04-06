class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        return solve(cardPoints, k);
    }
private:
    int solve(vector<int>& cardPoints, int k) {
        if(k == cardPoints.size())
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        int points = 0;
        
        for(int i = 0; i < k; ++i) {
            points += cardPoints[i];
        }
        int end = cardPoints.size() - 1;
        int maxPoints = points;
            
        for(int i = k - 1; i >= 0; --i) {
            points -= cardPoints[i];
            points += cardPoints[end--];
            
            maxPoints = max(maxPoints, points);
        }
        return maxPoints;
    }
};