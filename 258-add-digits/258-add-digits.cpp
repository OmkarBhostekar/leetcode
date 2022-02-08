class Solution {
public:
    int addDigits(int num) {
        if(num <10 and num>=0) return num;
        vector<int> v;
        while(num>0){
            int digit = num%10;
            v.push_back(digit);
            num /= 10;
        }
        return addDigits(accumulate(v.begin(),v.end(),0));
    }
};