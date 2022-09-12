class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        sort(t.begin(),t.end());
        int i=0,j=t.size()-1;
        if(t.size()==1){
            return t[0]<=p;
        }
        int score = 0;
        int ans = 0;
        while(i<j){
            while(p>=t[i]){
                p-=t[i];
                i++;
                score++;
            }
            ans = max(ans,score);
            if(score>0){
                p+=t[j];
                j--;
                score--;
            }else break;
        }
        return ans;
    }
};