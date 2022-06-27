class TrieNode{
  public:
    char val;
    bool end;
    unordered_map<int,TrieNode*> next;
    
    TrieNode(char x){
        this->val = x;
        this->end = false;
    }
};

class Trie {
public:
    
    unordered_map<char,TrieNode*> m;
    
    Trie() {
        
    }
    
    void insert(string word) {
        if(!m[word[0]]) m[word[0]] = new TrieNode(word[0]);
        TrieNode* temp = m[word[0]];
        for(int i=1;i<word.size();i++){
            int idx = word[i]-'a';
            if(!temp->next[idx]) temp->next[idx] = new TrieNode(word[i]);
            temp = temp->next[idx];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        if(!m[word[0]]) return false;
        TrieNode* temp = m[word[0]];
        for(int i=1;i<word.size();i++){
            int idx = word[i]-'a';
            if(!temp->next[idx]) return false;
            temp = temp->next[idx];
        }
        return temp->end;
    }
    
    bool startsWith(string word) {
        if(!m[word[0]]) return false;
        TrieNode* temp = m[word[0]];
        for(int i=1;i<word.size();i++){
            int idx = word[i]-'a';
            if(!temp->next[idx]) return false;
            temp = temp->next[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */