class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int i = 0;
        if(word[i] <= 90){ // Capital
            i++;
            if(word[i] <= 90){ // 2nd Capital
                while(i<n){
                    if(word[i] > 90) return false;
                    i++;
                }
            }else{
                while(i<n){
                    if(word[i] <= 90) return false;
                    i++;   
                }
            }
        }else{
            while(i < n){
                if(word[i] <= 90) return false;
                i++;
            }
        }
        return true;
    }
};