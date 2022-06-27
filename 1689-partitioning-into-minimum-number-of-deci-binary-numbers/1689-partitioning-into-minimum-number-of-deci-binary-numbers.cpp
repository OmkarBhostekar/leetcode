class Solution {
public:
    int minPartitions(string n) {
        int ans='\0';
        for(auto x: n){
            if(x>ans)
                ans = x;
            if(ans == '9') return 9;
        }
        return ans-'0';
    }
};