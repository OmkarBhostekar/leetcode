class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size()-1;
        while(row<matrix.size() and col>=0){
            int val = matrix[row][col];
            if(val == target) return true;
            if(target<val) col--;
            else row++;
            
        }
        return false;
    }
};