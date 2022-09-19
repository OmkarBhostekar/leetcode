class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> m;
        for(auto p: paths){
            string pre = "";
            int i=0;
            while(p[i]!=' ') pre += p[i++];
            i++;
            while(i<p.length()){
                string f = "",c="";
                while(p[i] != '(') f+=p[i++];
                i++;
                while(p[i] != ')') c+=p[i++];
                i+=2;
                m[c].push_back(pre+'/'+f);
            }
        }
        vector<vector<string>> ans;
        for(auto x: m){
            if(x.second.size()>1)
            ans.push_back(x.second);
        }
        return ans;
    }
};