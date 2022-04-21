class MyHashSet {
public:
    int arr[1000000+1] = {0};
    MyHashSet() {
    }
    
    void add(int key) {
        arr[key]++;
    }
    
    void remove(int key) {
        arr[key] = 0;
    }
    
    bool contains(int key) {
        return arr[key] != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */