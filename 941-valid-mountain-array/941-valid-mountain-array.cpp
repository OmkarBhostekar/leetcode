class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool up=true ,a=false,b=false;
        int size=arr.size();
        
        if(size < 3)return false;
        
        for(int i=1;i<size;++i){
            if(arr[i-1] < arr[i]){
                a=true;
                if(!up)return false;
            }else if(arr[i-1] > arr[i]){
                b=true;
                if(up)up=false;
            }else
                return false;
        }
        
        return a and b ;
    }
};