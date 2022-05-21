class Solution {
public:
    bool areAnagram(string str1, string str2){
        int n1 = str1.length();
        int n2 = str2.length();
 
        if (n1 != n2)
            return false;

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        for (int i = 0; i < n1; i++)
            if (str1[i] != str2[i])
                return false;

        return true;
    }
    
    vector<string> removeAnagrams(vector<string>& w) {
        stack<string> s;
        s.push(w[0]);
        for(int i=1;i<w.size();i++){
            if(!areAnagram(s.top(),w[i])){
                s.push(w[i]);
            }
        }
        vector<string> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};