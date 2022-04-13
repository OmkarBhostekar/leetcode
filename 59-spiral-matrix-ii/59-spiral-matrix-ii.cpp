class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        int s=0,e=n-1,t=0,b=n-1;
        n=1;
        while(s<=e or t<=b){
            if(s==e and t==b){
                v[s][e] = n++;
            }else{
                for(int i=s;i<e;i++)
                    v[t][i] = n++;
                for(int i=t;i<b;i++)
                    v[i][e] = n++;
                for(int i=e;i>s;i--)
                    v[b][i] = n++;
                for(int i=b;i>t;i--)
                    v[i][s] = n++;
            }
            s++;
            e--;
            t++;
            b--;
        }
        return v;
    }
};