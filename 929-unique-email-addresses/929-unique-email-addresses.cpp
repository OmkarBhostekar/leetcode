class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string e: emails){
            int idx = e.find("@");
            string local = e.substr(0,idx);
            string temp = "";
            for(auto ch: local){
                if(ch == '+') break;
                if(ch == '.') continue;
                temp += ch;
            }
            st.insert(temp+e.substr(idx));
        }
        return st.size();
    }
};