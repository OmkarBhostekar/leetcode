class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int x: stones){
            heap.push(x);
        }
        while(!heap.empty()){
            if(heap.size() == 1){
                return heap.top();
            }
            int y = heap.top();
            heap.pop();
            int x = heap.top();
            heap.pop();
            if(x!=y){
                heap.push(y-x);
            }
        }
        return 0;
    }
};