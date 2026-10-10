class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> cnt(100001,0);
        long long k=(long long)k1+k2;

        for(int i=0;i<nums1.size();i++){
            cnt[abs(nums1[i]-nums2[i])]++;
        }

        for(int i=100000;i>0 && k>0;i--){
            if(cnt[i]==0) continue;

            long long take=min(k,cnt[i]);
            cnt[i]--;
            cnt[i-1]+=1;
            k--;

            if(take>1){
                long long extra=min(k,cnt[i]);
                cnt[i]-=extra;
                cnt[i-1]+=extra;
                k-=extra;
            }

            i++;
        }

        long long ans=0;
        for(int i=0;i<=100000;i++){
            ans+=cnt[i]*i*i;
        }

        return ans;
    }
};