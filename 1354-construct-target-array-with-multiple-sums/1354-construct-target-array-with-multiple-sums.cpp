class Solution {
public:
    bool isPossible(vector<int>& target) {
        return daily(target);
    }
private:
    bool daily(vector<int>& target) {
        priority_queue<int> maxHeap;
        unsigned int sum = 0;
        
        for(int num: target) {
            sum += num;
            maxHeap.push(num);
        }
        
        while(maxHeap.top() != 1) {
            int num = maxHeap.top();
            maxHeap.pop();
            sum -= num;
            
            if(num <= sum || sum < 1)
                return false;
            
            num = num % sum;
            sum += num;
            
            if(num == 0)
                maxHeap.push(sum);
            else
                maxHeap.push(num);
        }
        return true;
    }
};