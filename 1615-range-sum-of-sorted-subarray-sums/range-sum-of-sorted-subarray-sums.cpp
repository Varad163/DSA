class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int total=0;

        for(int i=0;i<=nums.size()-1;i++){
            for (int j=i;j<=nums.size()-1;j++){
                total+=nums[j];
                ans.push_back(total);

            }
            total=0;
        }

        sort(ans.begin(),ans.end());

        const int MOD = 1e9 + 7;
        long long res = 0;

        for (int i = left - 1; i < right; i++) {
            res = (res + ans[i]) % MOD;
        }

        return res;

    }
};