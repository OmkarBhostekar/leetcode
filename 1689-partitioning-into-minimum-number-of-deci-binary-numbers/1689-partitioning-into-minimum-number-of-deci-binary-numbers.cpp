class Solution {
public:
    int minPartitions(string n) {
        int ans='\0';
        for(auto x: n){
            if(x>ans)
                ans = x;
        }
        return ans-'0';
    }
};