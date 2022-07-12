class Solution {
public:
    bool rec(vector<int>& ms, int maxLen, int a, int b, int c, int d, int i){
        if(i==ms.size()){
            return a == b && b == c && c == d;
        }
        if(a>maxLen || b>maxLen || c>maxLen || d>maxLen)
            return false;
        
        if(
            rec(ms,maxLen,a+ms[i],b,c,d,i+1) ||
            rec(ms,maxLen,a,b+ms[i],c,d,i+1) ||
            rec(ms,maxLen,a,b,c+ms[i],d,i+1) ||
            rec(ms,maxLen,a,b,c,d+ms[i],i+1)
        )
            return true;
        return false;
    }
    
    bool makesquare(vector<int>& ms) {
        sort(ms.begin(),ms.end(),greater<int>());
        int total = accumulate(ms.begin(),ms.end(),0);
        return rec(ms,total/4, 0, 0, 0, 0, 0);
    }
};