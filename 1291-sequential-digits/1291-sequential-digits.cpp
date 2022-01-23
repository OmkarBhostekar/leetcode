class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int mnd = to_string(low).length();
        int mxd = to_string(high).length();
        int diff = (mxd - mnd)+1;
        vector<int> ans;
        for(int i=mnd; i<=mxd; i++){
            for(int j=1; j<(10-i+1); j++){
                int temp = 0;
                int x = j;
                for(int k=i; k>0; k--){
                    temp = (10*temp) + x;
                    x++;
                }
                if(temp >= low and temp <= high){
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};