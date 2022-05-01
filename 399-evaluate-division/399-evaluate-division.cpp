class Solution {
public:
    void dfs(string s, string d, map<string,vector<pair<string,double>>>&m,set<string> &v, double &ans, double temp)
    {
        if(v.find(s) != v.end())
            return;
        v.insert(s);
        if(s == d){
            ans = temp;
            return;
        }else{
            for(auto a: m[s])
                dfs(a.first,d,m,v,ans,temp*a.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>> m;
        vector<double> ans;
        for(int i=0;i<e.size();i++){
            m[e[i][0]].push_back({e[i][1],v[i]});
            m[e[i][1]].push_back({e[i][0],1/v[i]});
        }
        for(int i=0;i<q.size();i++){
            string src = q[i][0];
            string dest = q[i][1];
            set<string> v;
            double x = -1.0;
            if(m.find(src) != m.end())
                dfs(src,dest,m,v,x,1.0);
            ans.push_back(x);
        }
        return ans;
    }
};