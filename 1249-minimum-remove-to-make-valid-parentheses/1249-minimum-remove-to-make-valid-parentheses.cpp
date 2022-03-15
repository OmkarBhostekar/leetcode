class Solution {
public:
    string minRemoveToMakeValid(string str) {
        stack<int> s;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '('){
                s.push(i);
            }else if(str[i] == ')'){
                if(s.empty()){
                    str[i] = '*';
                }else{
                    s.pop();
                }
            }
        }
        while(!s.empty()){
            str[s.top()] = '*';
            s.pop();
        }
        string ans = "";
        for(int i=0; i<str.length(); i++){
            if(str[i] != '*')
                ans.push_back(str[i]);
        }
        return ans;
    }
};