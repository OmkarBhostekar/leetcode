class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string e: emails){
            int idx = e.find("@");
            string temp = "";
            for(auto ch: e){
                if(ch == '+' || ch == '@') break;
                if(ch == '.') continue;
                temp += ch;
            }
            st.insert(temp+e.substr(idx));
        }
        return st.size();
    }
};