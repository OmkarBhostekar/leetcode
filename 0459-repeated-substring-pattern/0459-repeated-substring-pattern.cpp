class Solution {
public:
    vector<int> getFactors(int n){
        vector<int> v;
        for(int i=1; i*i <= n; i++){
            if(n%i == 0){
                v.push_back(i);
                if(i != n/i)
                    v.push_back(n/i);
            }
        }
        return v;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> f = getFactors(n);
        for(int len: f){
            if(len == n) continue;
            int x = n/len;
            bool flag = true;
            for(int i=0;i<len;i++){
                for(int j=0;j<x;j++){
                    if(s[i] != s[i+j*len]){
                        flag = false;
                    }
                }
            }
            if(flag) return true;
        }
        return false;
    }
};