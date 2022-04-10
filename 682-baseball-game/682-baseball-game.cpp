class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string x: ops){
            if(x == "C"){
                st.pop();
            }else if(x == "D"){
                st.push(st.top()*2);
            }else if(x == "+"){
                int temp = st.top();
                st.pop();
                int t2 = st.top()+temp;
                st.push(temp);
                st.push(t2);
            }else{
                st.push(stoi(x));
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};