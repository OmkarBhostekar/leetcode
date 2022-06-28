class LRUCache {
public:
    list<int> lru;
    unordered_map<int,list<int>::iterator> m;
    unordered_map<int,int> kv;
    int max;
    
    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        updateLRU(key);
        return kv[key];
    }
    
    void updateLRU(int key){
        if(kv.count(key))
            lru.erase(m[key]);
        lru.push_front(key);
        m[key] = lru.begin();
    }
    
    void evict(){
        m.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
    
    void put(int key, int value) {
        if(kv.size() == max && kv.count(key) == 0)
            evict();
        updateLRU(key);
        kv[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */