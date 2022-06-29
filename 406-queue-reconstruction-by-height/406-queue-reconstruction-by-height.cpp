class Solution {
public:
    static bool compare(vector<int>&A, vector<int>&B){
        if(A[0] == B[0]) return A[1] < B[1];
        return A[0] > B[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);
        vector<vector<int>> res;
        for(int i=0;i<people.size();i++){
            res.insert(res.begin()+people[i][1],people[i]);
        }
        return res;
    }
};