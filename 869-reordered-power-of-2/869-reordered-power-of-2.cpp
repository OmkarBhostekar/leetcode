unordered_set<string> st;
bool f = []{
    for(int i=0;i<32;i++){
        long x = pow(2,i);
        string y = to_string(x);
        sort(y.begin(),y.end());
        st.insert(y);
    }
    return true;
}();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string x = to_string(n);
        sort(x.begin(),x.end());
        return st.find(x) != st.end();
    }
};