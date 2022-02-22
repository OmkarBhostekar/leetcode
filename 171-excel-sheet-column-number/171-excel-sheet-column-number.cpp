class Solution {
public:
    int titleToNumber(string ct) {
        int ans = 0;
        for(char c : ct){
            int d = c - 'A' + 1;
            ans = ans * 26 + d;
        }
        return ans;
    }
};