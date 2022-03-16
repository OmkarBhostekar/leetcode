class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int a=0,b=0;
        int n = pushed.size();
        while(a<n or b<n){
            if(!s.empty()){
                if(s.top() == popped[b]){
                    s.pop();
                    b++;
                }else if(a<n){
                    s.push(pushed[a]);
                    a++;
                }else 
                    return false;
            }else if(a<n){
                s.push(pushed[a]);
                a++;
            }
        }
        return s.empty();
    }
};