class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> s;
        vector<int> ans(t.size(),0);
        s.push({t[0],0});
        int i=1;
        while(!s.empty() && i<t.size()){
            while(!s.empty() && s.top().first<t[i]){
                auto x = s.top();
                ans[x.second] = i - x.second;
                s.pop();
            }
            
            s.push({t[i],i});
            i++;
        }
        return ans;
    }
};