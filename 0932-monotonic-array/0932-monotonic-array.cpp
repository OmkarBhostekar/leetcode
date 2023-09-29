class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        int n = v.size();
        if(n<=2) return true;
        bool asc = true, desc = true;
        for(int i=1;i<n;i++){
            if(v[i-1]==v[i]) continue;
            else if(v[i-1]<v[i]) desc = false;
            else asc = false;
        }
        return asc || desc;
    }
};