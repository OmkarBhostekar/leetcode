class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int last = v[0];
        for(int i=1;i<v.size();i++){
            int tmp = v[i];
            v[i] = v[i]^last;
            last = tmp;
        }
        return v;
    }
};