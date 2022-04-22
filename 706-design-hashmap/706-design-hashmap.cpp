class MyHashMap {
public:
    set<int> keys;
    int arr[1000001];
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        keys.insert(key);
        arr[key] = value;
    }
    
    int get(int key) {
        if(keys.find(key) == keys.end())
            return -1;
        return arr[key];
    }
    
    void remove(int key) {
        keys.erase(key);
        arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */