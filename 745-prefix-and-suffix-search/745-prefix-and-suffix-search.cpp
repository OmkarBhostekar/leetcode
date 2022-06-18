class WordFilter {
public:
    unordered_map<string,int> m;
    WordFilter(vector<string>& words) {
        int index = 1;
        for(string word: words){
            for(int i=0;i<=word.length();i++){
                for(int j=0;j<=word.length();j++){
                    string prefAndSuff = word.substr(0,i) + "#" + word.substr(j);
                    m[prefAndSuff] = index;
                }
            }
            index++;
        }
    }
    
    int f(string prefix, string suffix) {
        string query = prefix + "#" + suffix;
        if(m[query])
            return m[query]-1;
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */