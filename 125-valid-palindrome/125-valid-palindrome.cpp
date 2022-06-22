class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]<48 or (s[i]>57 and s[i]<65) or (s[i]>90 and s[i]<97) or s[i]>122) ++i;
            else if(s[j]<48 or (s[j]>57 and s[j]<65) or (s[j]>90 and s[j]<97) or s[j]>122) --j;
            else {
                if(s[i]<97) s[i] = (char) s[i]+32;
                if(s[j]<97) s[j] = (char) s[j]+32;
                if(s[i] != s[j]) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};