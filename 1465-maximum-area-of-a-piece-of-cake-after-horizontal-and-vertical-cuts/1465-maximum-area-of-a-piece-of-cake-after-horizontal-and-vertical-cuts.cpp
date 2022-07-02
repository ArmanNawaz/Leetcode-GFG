class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return daily(h, w, horizontalCuts, verticalCuts);
    }
private:
    int daily(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int l = 0, b = 0;
        
        for(int i = 0; i < horizontalCuts.size() - 1; ++i)
            l = max(l, horizontalCuts[i + 1] - horizontalCuts[i]);
        
        for(int i = 0; i < verticalCuts.size() - 1; ++i)
            b = max(b, verticalCuts[i + 1] - verticalCuts[i]);
        
        int mod = 1e9 + 7;
        
        return (int)(((long)l * (long)b) % mod);
    }
};