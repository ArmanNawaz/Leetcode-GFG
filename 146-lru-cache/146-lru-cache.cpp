// Channa Sir 
class LRUCache {
    int capacity;
    list<pair<int, int>> que; // key-value pair where 1st element is most recently used
    unordered_map<int, list<pair<int, int>>::iterator> dict;
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(dict.find(key) == dict.end()) return -1;
        int result = dict[key] -> second;
        
        
        // touch
        que.erase(dict[key]);
        que.push_back({key, result});
        dict[key] = prev(que.end());
        return result;
    }
    
    void put(int key, int value) {
        if(dict.find(key) != dict.end()) {
            dict[key] -> second = value;
            
            que.erase(dict[key]);
        } else {
            if(que.size() == capacity) {
                // evict the LRU
                dict.erase(que.front().first);
                que.pop_front();
            }
        }
        que.push_back({key, value});
        dict[key] = prev(que.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */