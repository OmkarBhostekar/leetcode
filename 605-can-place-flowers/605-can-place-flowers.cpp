class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size() && n>0; i++){
            if(flowerbed[i] == 0){
                int next,prev;
                if(i == flowerbed.size()-1)
                    next = 0;
                else
                    next = flowerbed[i+1];
                if(i == 0)
                    prev = 0;
                else
                    prev = flowerbed[i-1];
                if(next == 0 and prev == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n==0;
    }
};