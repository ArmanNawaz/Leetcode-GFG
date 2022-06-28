class Solution {
public:
    int minDeletions(string s) {
        return daily(s);
    }
private:
    int daily(string s) {
        unordered_map<char, int> freqMap;
        priority_queue<int> freq;
        
        for(char ch: s)
            freqMap[ch]++;
        
        for(auto entry: freqMap)
            freq.push(entry.second);
        
        int count = 0;
        
        while(!freq.empty()) {
            int top = freq.top();
            freq.pop();
            
            if(!freq.empty() && freq.top() == top) {
                if(top != 1)
                    freq.push(top - 1);
                count++;
            }
        }
        return count;
    
    }
};