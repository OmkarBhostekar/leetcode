class Solution {
public:
    bool isPalindrome(string str, int s, int e){
        while(s<=e){
            if(str[s] == str[e]){
                s++;
                e--;
            }else return false;
        }
        return true;
    }
    
    bool validPalindrome(string str) {
        int s=0, e=str.length()-1;
        while(s<=e){
            if(str[s] == str[e]){
                s++;
                e--;
            }else return isPalindrome(str,s+1,e) || isPalindrome(str,s,e-1);
        }
        return true;
    }
};