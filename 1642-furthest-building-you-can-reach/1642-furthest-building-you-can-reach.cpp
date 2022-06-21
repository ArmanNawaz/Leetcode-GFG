class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return daily(heights, bricks, ladders);
    }
private:    
    int daily(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        
        for(int i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            
            if(diff > 0) 
                pq.push(diff);
            
            if(pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            if(bricks < 0)
                return i;
        }
        return n - 1;
    }
};