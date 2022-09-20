class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Rahul Sir
        // bfs
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            
            if(arr[idx] == 0) return true;
            
            if(arr[idx] < 0) continue;
            
            if(idx + arr[idx] < (int)arr.size()) q.push(idx + arr[idx]);
            if(idx - arr[idx] >= 0) q.push(idx - arr[idx]);

            arr[idx] = -1 * arr[idx];
        }
        return false;
    }
};