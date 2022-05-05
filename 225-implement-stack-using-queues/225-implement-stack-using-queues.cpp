class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q2.push(x);
        }else{
            q1.push(x);
        }
    }
    
    int size(){
        return max(q1.size(),q2.size());
    }
    
    int pop() {
        if(q1.empty()){
            if(size()>1){
                for(int i=0;i<size();i++){
                    q1.push(q2.front());
                    q2.pop();
                }
            }
            int x = q2.front();
            q2.pop();
            return x;
        }else{
            if(size()>1){
                for(int i=0;i<size();i++){
                    q2.push(q1.front());
                    q1.pop();
                }
            }
            int x = q1.front();
            q1.pop();
            return x;
        }
    }
    
    int top() {
        if(q1.empty()){
            return q2.back();
        }else{
            return q1.back();
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */