class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        return daily(boxTypes, truckSize);
    }
private:
    int daily(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto& b) {
            return a[1] > b[1];
        });
        
        int ans = 0;
        
        for(int i = 0; i < boxTypes.size(); ++i) {
            int boxes = boxTypes[i][0];
            int units = boxTypes[i][1];
            
            if(boxes <= truckSize) {
                ans += boxes * units;
                truckSize -= boxes;
            } else {
                ans += truckSize * units;
                truckSize = 0;
                break;
            }
            if(truckSize == 0) break;
        } 
        
        return ans;
    }
};