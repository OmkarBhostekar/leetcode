class Solution {
public:
    string reverseWords(string s) {
        int i,n=s.length();
        string ans = "";
        while(s[i] == ' ') i++;
        while(s[n-1] == ' ') n--;
        
        while(i<n){
            string temp = "";
            while(i<n && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(i>=n){
                ans = temp + ans;
                break;
            }else
                ans = ' '+ temp + ans;
            while(i<n && s[i] == ' ') i++;
        }
        return ans;
    }
};