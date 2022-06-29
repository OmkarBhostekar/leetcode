class Solution {
public:
    int maxDepth(string s) {
        int ans =0;
        stack<char> st;
        for(int i=0;i<s.length(); i++){
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') st.pop();
            if(st.size()>ans)
                ans = st.size();
        }
        return ans;
    }
};