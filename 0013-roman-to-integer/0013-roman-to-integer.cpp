class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int total = 0;
        for(int i=0;i<(int)s.length();i++){
            if(i+1<s.length() && mp[s[i]]< mp[s[i+1]]){
                total += mp[s[i+1]];
                total -= mp[s[i]];
                i++;
            }else{
                total += mp[s[i]];
            }
        }
        return total;
    }
};