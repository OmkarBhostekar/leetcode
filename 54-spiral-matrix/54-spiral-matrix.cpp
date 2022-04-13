class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int t=0,b=m.size()-1,s=0,e=m[0].size()-1,i;
        vector<int> ans;
        while(s<=e and t<=b){
            if(s==e and t==b){
                ans.push_back(m[s][e]);
            }else{
                if(s<=e)
                    for(i=s;i<=e;i++)
                        ans.push_back(m[t][i]);
                if(t+1<=b)
                    for(i=t+1;i<=b;i++)
                        ans.push_back(m[i][e]);
                if(e-1>=s and t != b)
                    for(i=e-1;i>=s;i--)
                        ans.push_back(m[b][i]);
                if(b-1>t and s!=e)
                    for(i=b-1;i>t;i--)
                        ans.push_back(m[i][s]);
            }
            s++;
            e--;
            t++;
            b--;
        }
        return ans;
    }
};