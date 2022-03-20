class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,set<pair<int,int>>> mpp;
        for(int i=0; i<tops.size(); i++){
            if(tops[i] == bottoms[i]){
                mpp[tops[i]].insert({i,3});
            }else{
                mpp[tops[i]].insert({i,1});
                mpp[bottoms[i]].insert({i,2});
            }
        }
        for(auto x: mpp){
            if(x.second.size() >= tops.size()){
                int tc = 0, bc = 0, ac=0;
                for(pair<int,int> a: x.second){
                    if(a.second == 1){
                        tc++;
                    }else if(a.second == 2){
                        bc++;
                    }else
                        ac++;
                }
                if(tc>=bc)
                    tc+=ac;
                else
                    bc+=ac;
                return min(tc,bc);
            }
        }
        return -1;
    }
};