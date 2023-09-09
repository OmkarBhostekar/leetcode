class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";
        int i=0,n=s.length();
        int j= n;
        reverse(s.begin(),s.end());
        while(i<j && s[i] == ' ') i++;
        while(i<j && s[i] != ' ') temp += s[i++];
        // cout << temp << endl;
        return temp.length();
    }

};