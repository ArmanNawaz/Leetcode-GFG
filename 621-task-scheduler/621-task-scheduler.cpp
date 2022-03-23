class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        return solve(tasks, n);
    }
private:
    // Rahul Sir
    int solve(vector<char>& tasks, int n) {
        unordered_map<char, int> hashMap;
        
        for(auto task: tasks)
            hashMap[task]++;
        vector<int> values;
        for(auto x: hashMap)
            values.push_back(x.second);
        
        sort(values.begin(), values.end());
        
        int maxFreq = values.back();
        int idleTime = (maxFreq - 1) * n;
        
        for(int i = values.size() - 2; i >= 0; --i) {
            idleTime -= min(values[i], maxFreq - 1);
        }
        idleTime = idleTime < 0 ? 0: idleTime;
        
        return tasks.size() + idleTime;
    }
};