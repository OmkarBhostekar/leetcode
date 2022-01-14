class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        int curr = 0;
        long long res =0;
        bool isNeg = false;
        int len = 0;
        //leading whitespace
        while(s[curr] == ' ')
            curr++;
        if(s[curr] == '+' || s[curr] == '-') {
            if(s[curr] == '-')
                isNeg = true;
            curr++;
        }
        while(true) {
            if(curr >= n)
                break;
            if(len >10) {
                return isNeg? -1*(1LL<<31):(1LL<<31)-1LL;
            }
            if(s[curr] == ' ')
                break;
            if(s[curr] == '.'){
                break;
            }
            if(s[curr] == '+' || s[curr]=='-')
                break;
            if(isalpha(s[curr]))
                break;
            res = res*10+(s[curr]-'0');
            curr++;
            if(res != 0)
                len++;
        }
        if(res >= ((1LL<<31)-1) and !isNeg)
            return (1LL<<31)-1LL;
        if(res >= (1LL<<31))
            return -1*(1LL<<31);
        return isNeg? -1*res: res;
    }
};