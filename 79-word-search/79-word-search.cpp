class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int ptr){
        if(ptr>=word.length()) return true;
        if( i>=board.size() || i<0 || j>=board[0].size() || j<0 || board[i][j] != word[ptr])
            return false;
        
        char key = board[i][j];
        board[i][j] = '#';
        if(dfs(board,word,i+1,j,ptr+1) || dfs(board,word,i-1,j,ptr+1) || dfs(board,word,i,j+1,ptr+1) || dfs(board,word,i,j-1,ptr+1))
            return true;
        board[i][j] = key;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};