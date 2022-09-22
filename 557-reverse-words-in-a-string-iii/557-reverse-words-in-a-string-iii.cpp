class Solution {
public:
    string reverseWords(string str) {
        int s=0,e=0,n=str.length();
        while(e<n){
            while(e<n && str[e] != ' ') e++;
            int i=s,j=e-1;
            while(i<=j)
                swap(str[i++],str[j--]);
            e++;
            s=e;
        }
        return str;
    }
};