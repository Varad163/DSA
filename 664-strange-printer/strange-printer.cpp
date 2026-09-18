class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }

        for(int len=2;len<=n;len++){
            for(int l=0;l+len-1<n;l++){
                int r=l+len-1;

                dp[l][r]=dp[l+1][r]+1;

                for(int k=l+1;k<=r;k++){
                    if(s[l]==s[k]){
                        int left=(k==l+1)?0:dp[l+1][k-1];

                        dp[l][r]=min(dp[l][r],left+dp[k][r]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};