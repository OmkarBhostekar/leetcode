class Solution {
public:
    bool isgood(int x){
        int cnt=0;
        while(x>0){
            int r = x%10;
            if(r&1) cnt--;
            else cnt++;
            x /= 10;
        }
        return cnt==0;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        int ans = 0;
        for(int i=10;i<99;i++){
            if(low<=i && i<=high && isgood(i) && i%k==0) {
                ans++;
            }
        }
        if(high>1e3){
            int x = 1000/k;
            if(1000%k !=0) x++;
            for(int i=k*x;i<9999;i+=k){
                if(low<=i && i<=high && isgood(i) && i%k==0) ans++;
            }
        }
        if(high>1e5){
            int x = 100000/k;
            if(100000%k !=0) x++;
            for(int i=k*x;i<999999;i+=k){
                if(low<=i && i<=high && isgood(i) && i%k==0) ans++;
            }
        }
        if(high>1e7){
            int x = 10000000/k;
            if(10000000%k !=0) x++;
            for(int i=k*x;i<99999999;i+=k){
                if(low<=i && i<=high && isgood(i) && i%k==0) ans++;
            }
        }
        return ans;
    }
};