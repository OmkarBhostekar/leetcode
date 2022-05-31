class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k) return false;
        
        int n = pow(2,k);
        vector<int> v(n,0);
        
        for(int i=0;i<s.length()-k+1;i++){
            string temp="";
            for(int j=i;j<i+k;j++)
                temp += s[j];
            int num = stoi(temp, 0, 2);
            if(v[num] == 0)
                v[num] = 1;
        }
        for(int i=0;i<n;i++){
            if(!v[i])
                return false;
        }
        return true;
    }
};