class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(t.size() == 0) return false;
        
        
        int i=0,j=0;
        while(j<t.length() and i<s.length()){
            if(s[i] == t[j]) i++;
            j++;
        }
        if(i == s.length())
            return true;
        
        return false;
    }
};