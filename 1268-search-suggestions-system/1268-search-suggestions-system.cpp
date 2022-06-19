class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto start = products.begin();
        sort(start,products.end());
        vector<vector<string>>ans;
        vector<string>temp;
        string cur = "";    
        for(auto c: searchWord){
            cur += c;
            temp.clear();
            start = lower_bound(start,products.end(),cur);
            for(int i=0;i<3 && start+i!=products.end();i++){
                string s = *(start+i);
                if(s.find(cur)) break;
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};