class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = 0;
        while(pow(minutesToTest / minutesToDie + 1, ans) < buckets)
            ans++;
        return ans;
    }
};