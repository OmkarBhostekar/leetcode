class Solution {
public:
    string mul(string s, int x){
        int n = s.length();
        int carry = 0;
        for(int i=n-1;i>=0;i--){
            int y = s[i]-'0';
            y *= x;
            y += carry;
            carry = y / 10;
            y = y%10;
            char z = char(y+'0');
            s[i] = z;
        }
        if(carry>0){
            string c = to_string(carry);
            s = c + s;
        }
        return s;
    }

    string add(string a, string b){
        string ans = "";
        int carry = 0;
        for(int i=a.length()-1;i>=0;i--){
            int x = a[i]-'0', y = b[i]-'0';
            x = x + y + carry;
            carry = x/10;
            x %= 10;
            ans.push_back(char(x+'0'));
        }
        reverse(ans.begin(),ans.end());
        if(carry){
            if(ans[0] == '0') ans[0] = char(carry+'0');
            else ans = to_string(carry) + ans;
        }
        return ans;
    }

    string multiply(string num1, string num2) {
        vector<string> v;
        int maxLen = 0;
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num2.size();i++){
            string temp = mul(num1, num2[i]-'0');
            // cout << num1 << " " << num2[i] << " " << temp << endl;
            for(int j=0;j<i;j++){
                temp = temp+'0';
            }
            maxLen = max(maxLen,(int)temp.length());
            v.push_back(temp);
        }
        maxLen++;
        // add additional starting 0
        for(int i=0;i<v.size();i++){
            int rm = maxLen-v[i].length();
            string x = "";
            for(int j=0;j<rm;j++) x += '0';
            v[i] = x + v[i];
        }
        string cur = v[0];
        for(int i=1;i<v.size();i++){
            cur = add(cur,v[i]);
        }
        string ans = "";
        int i=0;
        while(i<cur.length() && cur[i]=='0') i++;
        if(i==cur.length()) return "0";
        while(i<cur.length()){
            ans += cur[i];
            i++;
        }
        return ans;
    }
};