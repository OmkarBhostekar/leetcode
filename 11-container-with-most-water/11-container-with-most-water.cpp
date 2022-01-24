class Solution {
public:
    int maxArea(vector<int>& h) {
        int m = INT_MIN;
        int s = 0;
        int e = h.size()-1;
        if(e==0) return h[0];
        while(s<e){
            if(s == e){
                m = max(m,h[s]);
                s++;
                e--;
            }else{
                int a = min(h[s],h[e])*(e-s);
                m = max(m,a);
                if(h[s]<h[e])
                    s++;
                else
                    e--;
            }
        }
        return m;
    }
};