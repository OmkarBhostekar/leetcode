class Solution {
public:
    vector<string> split(string str, char del){
      string temp = "";
      vector<string> v;
      for(int i=0; i<(int)str.size(); i++){
         if(str[i] != del){
            temp += str[i];
         } else{
            v.push_back(temp);
            temp = "";
         }
      }
      v.push_back(temp);
      return v;
    }
    
    bool wordPattern(string pattern, string s) {
        int n = pattern.length();
        map<char,string> mpp;
        set<string> sc;
        vector<string> words = split(s,' ');
        if(n != words.size()) return false;
        for(int i=0; i<n; i++){
            char x = pattern[i];
            if(mpp[x] == "" and sc.find(words[i]) == sc.end()){
                mpp[x] = words[i];
                sc.insert(words[i]);
            }else if(mpp[x] != words[i]){
                return false;
            }
        }
        return true;
    }
};