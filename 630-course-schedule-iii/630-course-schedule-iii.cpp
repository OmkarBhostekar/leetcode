class Solution {
public:
    static bool compare(vector<int> &A, vector<int>&B){
        return A[1] < B[1];
    }
    
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),compare);
        priority_queue<pair<int,int>> pq;
        int days=0;
        
        for(int i=0;i<c.size();i++){
            days += c[i][0];
            pq.push(make_pair(c[i][0],c[i][1]));
            if(days>c[i][1]){
                days -= pq.top().first;
                pq.pop();
            }
        }
        return pq.size();
    }
};