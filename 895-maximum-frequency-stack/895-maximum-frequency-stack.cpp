class FreqStack {
public:
    int maxFreq = 0;
    unordered_map<int,stack<int>> mp;
    unordered_map<int,int> count;

    FreqStack() {
        
    }
    
    void push(int val) {
        count[val]++;
        mp[count[val]].push(val);
        maxFreq = max(maxFreq,count[val]);
    }
    
    int pop() {
        
        int x = mp[maxFreq].top();
        count[x]--;
        mp[maxFreq].pop();
        if(mp[maxFreq].empty())
            maxFreq--;

        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */