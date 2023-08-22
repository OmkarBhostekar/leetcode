class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        vector<int> s;
        int cnt=0;
        for(int i=0;i<f.size();i++){
            if(f[i]==0) cnt++;
            else{
                s.push_back(cnt);
                while(i+1<f.size() && f[i+1]==1) i++;
                cnt = 0;
            }
        }
        s.push_back(cnt);
        if(s.size()==1){
            n -= (s[0]+1)/2;
        }else {
            n -= (s[0]/2);
            for(int i=1;i<s.size()-1;i++){
                s[i]-=2;
                n -= (s[i]+1)/2;
            }
            n -= (s[s.size()-1])/2;
        }
        return n<=0;
    }
};