class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int start=0,end=0;
        while(start<chars.size()){
            chars[i++] = chars[start];
            while(end+1<chars.size() && chars[start] == chars[end+1]) end++;
            if(start != end) {
                string x = to_string(end-start+1);
                for(auto y: x) chars[i++] = y;
                
            }
            start = end = end+1;
        }
        return i;
    }
};