class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n= arr.size();
        unordered_map<int, vector<int>>mymap;
        int steps=0;
        queue<int>q;
        q.push(0);
        vector<int>visited(n,0);
        visited[0]=1;
        for(int i=0;i<n;i++)
        {
            mymap[arr[i]].push_back(i);
        }
        while(!q.empty())
        {
            int size1=q.size()-1;
            for(int size=size1;size>=0;size--)
            {
                int i= q.front();
                q.pop();
                 if (i == n - 1) return steps;
                vector<int>&next= mymap[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);
                for(int j: next)
                {
                    if(j>=0 && j<n && visited[j]!=1)
                    {
                        visited[j]=1;
                        q.push(j);
                    }
                }
                
                  mymap[arr[i]].clear();
            }
            steps++;
          
        }
        return steps;
    }
};