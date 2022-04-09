class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return solve(nums, k);
    }
private:
    struct comparator{
        bool operator()(pair<int, int> &x, pair<int, int> &y){
            return y.second < x.second;
        }
    };
    vector<int> solve(vector<int>& nums, int k){
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> minHeap;
        
        unordered_map<int, int> freq;
        
        for(int num: nums) freq[num]++;
        int i = 0;
        for(auto entry: freq){
            if(i < k){
                minHeap.push(entry);
            }
            else{
                if(entry.second > minHeap.top().second){
                    minHeap.pop();
                    minHeap.push(entry);
                }
            }
            i++;
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return ans;       
    }
    
};