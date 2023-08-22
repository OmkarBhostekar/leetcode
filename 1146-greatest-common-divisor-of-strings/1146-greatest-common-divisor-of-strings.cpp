class Solution {
public:
    bool check(string &pre, string &s){
        int n = pre.length();
        int j=0;
        for(int i=0;i<s.length();i++,j++){
            if(s[i] != pre[j%n]){
                return false;
            }
        }
        if(j%n != 0) return false;
        return true;
    }
    string gcdOfStrings(string s1, string s2) {
        if(s1.length()>s2.length())
            swap(s1,s2);
        string ans = "";
        string pre = "";
        for(int i=0;i<s1.length();i++){
            pre += s1[i];
            if(check(pre,s1) && check(pre,s2))
                ans = pre;
        }
        return ans;
    }
};