class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size(),i,j;
        vector<pair<int,int>> flag;
        for(i=0;i<n;i++){
            int x=0,l=0;
            for(auto ch:words[i]){
                x=(x|(1<<((int)(ch-'a'))));
                l++;
            }
            flag.push_back({x,l});
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if((flag[i].first & flag[j].first)==0){
                   res=max(res,(flag[i].second*flag[j].second)) ;
                }
            }
        }
        return res;
    }
};