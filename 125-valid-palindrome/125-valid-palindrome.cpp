class Solution {
public:
    bool isValid(char ch){
	    return (ch>=48 and ch<=57) or (ch>=65 and ch<=90) or (ch>=97 and ch<=122);
    }

    
    bool isPalindrome(string s) {
        int n = s.length(), start=0, end=n-1;
        while(start<=end){
            if(start == end) return true;
            bool a=isValid(s[start]), b=isValid(s[end]);
            if(a && b){
                if(isdigit(s[start]) and isdigit(s[end]) and s[start] != s[end]) return false;
                else if((isdigit(s[start]) and !isdigit(s[end])) or (!isdigit(s[start]) and isdigit(s[end]))) return false;
                else if(tolower(s[start]) != tolower(s[end])) return false;
                start++;
                end--;
            }
            if(!a) start++;
            if(!b) end--;
        }
        return true;
    }
};