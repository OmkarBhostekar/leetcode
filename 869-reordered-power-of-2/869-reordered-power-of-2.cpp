unordered_set<string> st;
bool f = []{
    for(int i=0;i<32;i++){
        long x = pow(2,i);
        st.insert(to_string(x));
    }
    return true;
}();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string x = to_string(n);
        sort(x.begin(),x.end());
        do{
            if(x[0] != '0' && st.find(x) != st.end())
                return true;
        }while(next_permutation(x.begin(),x.end()));
        return false;
    }
};