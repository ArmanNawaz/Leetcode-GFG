class Solution {
    struct comparator {
        bool operator() (const pair<string, int>& a, const pair<string, int>& b) {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        
        for(string& word: words)
            freq[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> heap;
        
        for(auto entry: freq) 
            heap.push({entry.first, entry.second});
        
        vector<string> ans;
        
        while(k--) {
            ans.push_back(heap.top().first);
            heap.pop();
        }

        return ans;
    }
};