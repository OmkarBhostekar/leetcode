class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(vector<int> p: points){
            x.push_back(p[0]);
        }
        sort(x.begin(),x.end());
        int m = 0;
        for(int i=1; i<x.size();i++){
            m = max(m,(x[i]-x[i-1]));
        }
        return m;
    }
};