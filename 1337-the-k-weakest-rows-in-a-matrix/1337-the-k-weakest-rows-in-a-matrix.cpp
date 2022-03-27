class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        return solve(mat, k);
    }
private:
    struct comparator{
        bool operator()(pair<int, int> &x, pair<int, int> &y){
            if(x.second == y.second)
                return x.first < y.first;
            return y.second > x.second;
        }
    };
    vector<int> solve(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> maxHeap;
        vector<int> stren(mat.size());
        
        for(int i = 0; i < mat.size(); i++){
            stren[i] = count(mat[i].begin(), mat[i].end(), 1);
        }
        for(int i = 0; i < k; i++){
            maxHeap.push(make_pair(i, stren[i]));
        }
        for(int i = k; i < stren.size(); i++){
            if(stren[i] < maxHeap.top().second){
                maxHeap.pop();
                maxHeap.push(make_pair(i, stren[i]));
            }
        }
        vector<int> res;
        while(!maxHeap.empty()){
            pair<int, int> entry = maxHeap.top();
            res.push_back(entry.first);
            maxHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};