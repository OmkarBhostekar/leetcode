class Node{
public:
    Node* children[2] ;
    int count ;
    Node(){
        count = 0 ;
        children[0] = NULL;
        children[1] = NULL;
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(int num , int op){
        Node* crawler = root ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            if(crawler->children[isSet] == NULL){
                crawler->children[isSet] = new Node() ;
            }
            crawler = crawler->children[isSet] ;
            crawler->count += op ;
        }
    }
    int search(int num){
        Node* crawler = root ;
        int maxval = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            bool need = not isSet ;
            if(crawler->children[need] != NULL and crawler->children[need]->count > 0){
                maxval = maxval | (1 << i) ;
                crawler = crawler->children[need] ;
            }
            else{
                crawler = crawler->children[isSet] ;
            }
        }
        return maxval ;
    }
};

class Solution {
public:
    Trie *t;
    vector<int> maxGeneticDifference(vector<int>& p, vector<vector<int>>& qs) {
        t = new Trie() ;
        
        int n = p.size() ;
        vector<vector<pair<int,int>>> queries(n);
        
        for(int i = 0 ; i < qs.size() ; i++){
            int node = qs[i][0] ;
            int val = qs[i][1] ;
            queries[node].push_back({val , i}) ;
        }
        int root = 0 ;
        vector<vector<int>> adj(n) ;
        for(int i = 0 ; i < n ; i++){
            if(p[i] == -1){
                root = i ;
                continue ;
            }
            adj[p[i]].push_back(i) ;
        }
        vector<int> ans(qs.size()) ;
        function<void(int)> dfs = [&](int node){
            t->insert(node,1);
            for(pair<int,int> &q : queries[node]){
                int val = q.first ;
                int idx = q.second ;
                
                int maxval = t->search(val) ;
                ans[idx] = maxval ;
            }
        
            // find its childrens queries
            for(int u : adj[node]){
                dfs(u);
            }
            t->insert(node,-1);
        };
        dfs(root);
        return ans;
    }
};