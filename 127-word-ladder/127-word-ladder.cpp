class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        queue<string> q;
        q.push(start);
        int n = start.size();
        unordered_set<string> word;
        for(string w: wordList){
            word.insert(w);
        }
        if(word.find(end) == word.end()) return 0;
        int len = 0;
        while(!q.empty()){
            len++;
            int qlen = q.size();
            for(int i=0; i<qlen; i++){
                string s = q.front();
                q.pop();
                for(int j=0; j<n; j++){
                    char c = s[j];
                    for(char ch='a'; ch<='z'; ch++){
                        s[j] = ch;
                        if(s == end) return len+1;
                        if(word.find(s) == word.end()) continue;
                        word.erase(s);
                        q.push(s);
                    }
                    s[j] = c; 
                }
            }
        }
        return 0;
    }
};