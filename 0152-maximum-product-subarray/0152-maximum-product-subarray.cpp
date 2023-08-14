class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        if(n==1) return v[0];
        vector<int> p(n), s(n);
        p[0] = v[0];
        s[n-1] = v[n-1];
        for(int i=1;i<n;i++){
            p[i] = v[i]*(p[i-1] ==  0 ? 1: p[i-1]);
            s[n-i-1] = v[n-i-1]*(s[n-i]==0 ? 1 : s[n-i]);
        }
        cout << p[1] << " " << s[0] << endl;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max({ans,p[i],s[i]});
        }
        return ans;
    }
};