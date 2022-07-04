class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> v(edges.size()+1);
        for(auto edge: edges){
            v[edge[0]-1]++;
            v[edge[1]-1]++;
        }
        for(int i=0;i<v.size();i++) 
            if(v[i] == edges.size()) 
                return i+1;
        return -1;
    }
};