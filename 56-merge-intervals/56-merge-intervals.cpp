class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> v1, const vector<int> v2) {return v1[0] < v2[0];});
        int start = intervals[0][0];
        int end = intervals[0][1];
        int i = 1;
        vector<vector<int>> ans;
        while(i < intervals.size()){
            if(end >= intervals[i][0])
                end = max(end, intervals[i][1]);
            else{
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};