class Solution {
public:
    int search(vector<int>& n, int t) {
        int s=0, e=n.size()-1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(n[m] == t)
                return m;
            if(t < n[m]){
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return -1;
    }
};