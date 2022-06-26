class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        while(i<matrix.size() && target>=matrix[i][0]) i++;
        if(i==0) return false;
        i--;
        return binary_search(matrix[i].begin(),matrix[i].end(),target);
    }
};