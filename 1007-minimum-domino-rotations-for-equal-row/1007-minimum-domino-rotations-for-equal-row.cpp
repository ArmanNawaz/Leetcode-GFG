class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        vector<int> faceA(7), faceB(7), same(7);
        
        for(int i = 0; i < n; ++i) {
            ++faceA[tops[i]];
            ++faceB[bottoms[i]];
            
            if(tops[i] == bottoms[i])
                ++same[tops[i]];
        }
        
        int minRotation = INT_MAX;
        
        for(int i = 1; i < 7; ++i) {
            if(faceA[i] + faceB[i] - same[i] == n)
                minRotation = min(minRotation , min(faceA[i], faceB[i]) - same[i]);
        }
        
        if(minRotation == INT_MAX) return -1;
        return minRotation;
    }
};