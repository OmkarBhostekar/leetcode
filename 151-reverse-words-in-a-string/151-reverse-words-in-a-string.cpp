class Solution {
public:
    string reverseWords(string s) {
        int start=0,end=0,n=s.length();
        string ans = "";
        while(s[start] == ' ') start++;
        end=start;
        while(s[n-1] == ' ') n--;
        
        while(start<n && end<n){
            while(end<n && s[end] != ' ') end++;
            if(end>=n)
                ans = s.substr(start,end-start) + ans;
            else
                ans = ' '+s.substr(start,end-start) + ans;
            while(s[end] == ' ') end++;
            start = end;
        }
        return ans;
    }
};