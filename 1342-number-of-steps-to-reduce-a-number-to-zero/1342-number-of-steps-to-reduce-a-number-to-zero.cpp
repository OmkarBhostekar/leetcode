class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        c += (num%2);
        while(num>0){
            num /= 2;
            c += (num%2);
            num -= (num%2);
            c++;
        }
        return c;
    }
};