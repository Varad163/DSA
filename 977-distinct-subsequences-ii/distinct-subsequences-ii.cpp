class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        long long mod=1000000007;

        vector<long long> dp(n+1,0);
        vector<int> last(26,-1);

        dp[0]=1;

        for(int i=0;i<n;i++){
            int ch=s[i]-'a';

            dp[i+1]=(2*dp[i])%mod;

            if(last[ch]!=-1){
                dp[i+1]=(dp[i+1]-dp[last[ch]]+mod)%mod;

            }

            last[ch]=i;
        }

        return (dp[n]-1+mod)%mod;
    }
};