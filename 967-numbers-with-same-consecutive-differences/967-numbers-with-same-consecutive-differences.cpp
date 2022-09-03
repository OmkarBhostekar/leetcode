class Solution {
public:
    int getNum(char c){return c-'0';}
    void rec(int n, string num, int k, unordered_set<string> &ans){
        if(n==0){
            ans.insert(num);
            return;
        }
        int digit = getNum(num[num.length()-1]);
        if(digit-k >= 0){
            string x = num;
            x += to_string(digit-k);
            rec(n-1,x,k,ans);
        }
        if(digit+k <= 9){
            string x = num;
            x += to_string(digit+k);
            rec(n-1,x,k,ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<string> temp;
        vector<int> ans;
        for(int i=1;i<=9;i++){
            string x = to_string(i);
            rec(n-1,x,k,temp);
        }
        for(auto x: temp)
            ans.push_back(stoi(x));
        return ans;
    }
};