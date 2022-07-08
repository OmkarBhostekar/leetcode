class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        int i=0;
        while(s[i] == ' ') i++; // skip starting empty
        while(i<n){
            int j = i;
            while(i < n && s[i] != ' ') i++;
            string temp = s.substr(j,i-j);
            ans = " " + temp + ans;
            while(i < n && s[i] == ' ') i++;
        }
        return ans.substr(1);        
    }
};