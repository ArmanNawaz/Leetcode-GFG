class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(!minHeap.empty() && num < minHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        int diff = minHeap.size() - maxHeap.size();
        
        if(diff > 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(diff < -1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
    }
    
    double findMedian() {
        
        if(maxHeap.size() > minHeap.size())
            return (double)maxHeap.top();
        
        else if(maxHeap.size() < minHeap.size())
            return (double)minHeap.top();
        
        else
            return (minHeap.top() + maxHeap.top()) / 2.0;
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */