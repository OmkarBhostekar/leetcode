class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(auto ch: ops){
            if(ch == "C"){
                v.pop_back();
            }else if(ch == "D"){
                v.push_back(v.back()*2);
            }else if(ch == "+"){
                v.push_back(v.back()+v[v.size()-2]);
            }else{
                v.push_back(stoi(ch));
            }
        }
        return accumulate(v.begin(),v.end(),0);
    }
};