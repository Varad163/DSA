class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long,4>> a(n);
        for(int i=0;i<n;i++){
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(),a.end(),[](auto &x,auto &y){
            return x[1] < y[1];
        });

        // p[i] = number of intervals before i which don't overlap with i
        vector<int> p(n);

        for(int i=0;i<n;i++){
            int l = a[i][0];

            int lo=0,hi=i-1,ans=-1;

            while(lo<=hi){
                int mid=(lo+hi)/2;

                if(a[mid][1] < l){
                    ans=mid;
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }

            p[i]=ans+1;
        }

        vector<vector<long long>> dp(n+1,vector<long long>(5,0));
        vector<vector<vector<int>>> path(n+1,vector<vector<int>>(5));

        for(int i=1;i<=n;i++){
            int idx=i-1;

            for(int k=1;k<=4;k++){
                // Don't take current interval
                dp[i][k]=dp[i-1][k];
                path[i][k]=path[i-1][k];

                // Take current interval
                if(k==1){
                    long long score=a[idx][2];
                    vector<int> cur={(int)a[idx][3]};

                    if(score>dp[i][k] ||
                       (score==dp[i][k] && cur<path[i][k])){
                        dp[i][k]=score;
                        path[i][k]=cur;
                    }
                }
                else if(p[idx]>0 || k==1){
                    long long score=a[idx][2]+dp[p[idx]][k-1];

                    vector<int> cur=path[p[idx]][k-1];
                    cur.push_back((int)a[idx][3]);

                    sort(cur.begin(),cur.end());

                    if(score>dp[i][k] ||
                       (score==dp[i][k] && cur<path[i][k])){
                        dp[i][k]=score;
                        path[i][k]=cur;
                    }
                }
            }
        }

        long long best=0;
        vector<int> ans;

        for(int k=1;k<=4;k++){
            if(dp[n][k]>best ||
               (dp[n][k]==best && path[n][k]<ans)){
                best=dp[n][k];
                ans=path[n][k];
            }
        }

        return ans;
    }
};