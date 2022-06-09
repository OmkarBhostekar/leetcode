class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int i=0,j=n.size()-1;
        while(i<=j){
            if(n[i]+n[j] == t){
                return {i+1,j+1};
            }else if(n[i]+n[j]>t){
                j--;
            }else {
                i++;
            }
        }
        return {};
    }
};