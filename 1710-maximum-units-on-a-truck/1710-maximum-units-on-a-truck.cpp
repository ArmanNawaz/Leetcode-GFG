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
            int boxesChoosen = min(boxTypes[i][0], truckSize);
            int units = boxTypes[i][1];
            
            ans += boxesChoosen * units;
            truckSize -= boxesChoosen;
            
            if(truckSize == 0) break;
        } 
        
        return ans;
    }
};