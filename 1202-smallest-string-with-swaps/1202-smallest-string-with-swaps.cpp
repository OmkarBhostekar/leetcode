class Solution {
public:
    
    static const int N = 1e5 + 1;
    vector<int> adj[N];
    bool visited[N];
    
    void DFS(string &s, int i, vector<char>& chars, vector<int>& ind){
        chars.push_back(s[i]);
        ind.push_back(i);
        
        visited[i] = true;
        for(int nei: adj[i]){
            if(!visited[nei])
                DFS(s,nei,chars,ind);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto pair: pairs){
            int src = pair[0];
            int dest = pair[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        for(int i=0; i<s.length(); i++){
            if(!visited[i]){
                vector<char> chars;
                vector<int> ind;
                DFS(s,i,chars,ind);
                
                sort(chars.begin(),chars.end());
                sort(ind.begin(),ind.end());
                for(int j=0;j<chars.size();j++)
                    s[ind[j]] = chars[j];
            }
        }
        return s;
    }
};