class MyHashMap {
public:
    unordered_map<int, int> hashMap;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        if(hashMap.find(key) != hashMap.end())
            return hashMap[key];
        return -1;
    }
    
    void remove(int key) {
        hashMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */