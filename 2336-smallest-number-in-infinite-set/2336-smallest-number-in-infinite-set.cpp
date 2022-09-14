class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> mySet;
public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; ++i) {
            mySet.insert(i);
            minHeap.push(i);
        }
    }
    
    int popSmallest() {
        int x = minHeap.top();
        
        mySet.erase(x);
        minHeap.pop();
        
        return x;
    }
    
    void addBack(int num) {
        if(mySet.find(num) == mySet.end()) {
            mySet.insert(num);
            minHeap.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */