class Solution {
public:
    string convertToTitle(int cn) {
        string ans = "";
        while(cn){
            cn--;
            int r = cn%26;
            char x = 'A'+r;
            ans = x + ans;
            cn /= 26;
        }
        return ans;
    }
};