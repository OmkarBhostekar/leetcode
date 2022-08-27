class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        int ans=INT_MIN;

        for(int start=0;start<m;start++){
            for(int end=start;end<m;end++){
                set<int>s={0};

                int prefSum=0;

                for(int i=0;i<n;i++){
                    int sum=matrix[i][end];

                    if(start>0){
                        sum-=matrix[i][start-1];
                    }
                    prefSum+=sum;

                    auto it=s.lower_bound(prefSum-k);
                    if(it!=s.end()){
                        ans=max(ans,prefSum-(*it));
                    }
                    s.insert(prefSum);
                }
            }
        }
        return ans;
    }
};