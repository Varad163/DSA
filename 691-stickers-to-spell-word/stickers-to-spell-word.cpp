class Solution {
public:
    unordered_map<string,int> dp;

    int solve(string target, vector<string>& stickers) {
        if(target.empty())
            return 0;

        if(dp.count(target))
            return dp[target];

        int ans=100;

        for(string s:stickers){
            vector<int> cnt(26,0);

            for(char c:s)
                cnt[c-'a']++;

            bool used=false;
            string rem="";

            for(char c:target){
                if(cnt[c-'a']>0){
                    cnt[c-'a']--;
                    used=true;
                }
                else{
                    rem+=c;
                }
            }

            if(used){
                int x=solve(rem,stickers);

                if(x!=100)
                    ans=min(ans,1+x);
            }
        }

        return dp[target]=ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        int ans=solve(target,stickers);

        if(ans==100)
            return -1;

        return ans;
    }
};