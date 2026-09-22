class Solution {
public:
    vector<long long> resultArray(vector<int>& nums,int k) {
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);

        for(int x:nums){
            vector<long long> ndp(k,0);

            x%=k;

            // subarray containing only nums[i]
            ndp[x]++;

            // extend previous subarrays
            for(int j=0;j<k;j++){
                if(dp[j]){
                    int r=(j*x)%k;
                    ndp[r]+=dp[j];
                }
            }

            for(int j=0;j<k;j++)
                ans[j]+=ndp[j];

            dp=ndp;
        }

        return ans;
    }
};