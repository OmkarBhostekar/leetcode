class Solution {
public:
    int longestValidParentheses(string str) {
        stack<pair<char,int>> s;
        vector<int> dp(str.length(),0);
        for(int i=0;i<str.length(); i++){
            if(str[i] == '(')
                s.push({str[i],i});
            else if(!s.empty() and s.top().first == '('){
                auto x = s.top();
                s.pop();
                dp[x.second] = 1;
                dp[i] = 1;
            }
        }
        int ans = 0;
        int cur = 0;
        for(int x: dp){
            if(x)
                cur++;
            else{
                ans = max(ans,cur);
                cur = 0;
            }
        }
        ans = max(ans,cur);
        return ans;
    }
};