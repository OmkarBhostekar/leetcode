class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int> pq;
        for(int i=0;i<h.size()-1;i++){
            if(h[i] >= h[i+1]) continue;
            b -= h[i+1]-h[i];
            pq.push(h[i+1]-h[i]);
            if(b<0){
                int x = pq.top();
                pq.pop();
                b += x;
                if(l) l--;
                else return i;
            }
        }
        return h.size() - 1;
    }
};