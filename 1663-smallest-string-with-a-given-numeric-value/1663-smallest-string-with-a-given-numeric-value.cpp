class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> v(n,1);
        k = k-n;
        int i=v.size()-1;
        while(k>0 && i>=0){
            int r = k>25 ? 25 : k;
            v[i] += r;
            k -= r;
            i--;
        }
        string ans = "";
        for(int x: v){
            char ch = 'a'-1+x;
            ans += ch;
        }
        return ans;
    }
};