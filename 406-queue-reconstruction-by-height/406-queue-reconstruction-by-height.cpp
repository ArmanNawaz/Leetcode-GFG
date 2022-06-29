class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        return daily(people);
    }
private:
    vector<vector<int>> daily(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        
        
        int n = people.size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; ++i) {
            int idx = people[i][1];
            
            ans.insert(ans.begin() + idx, people[i]);
        }
        return ans;
    }
};