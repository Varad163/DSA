class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1) return 1;

        vector<long long> dp(n, 0);

        for (int i = 0; i < m; i++) {
            long long left = 0;

            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    dp[j] = 1;
                    left = 1;
                    continue;
                }

                if (i == m - 1 && j == n - 1) {
                    return (dp[j] + left) % MOD;
                }

                if (grid[i][j] == 0) {
                    long long ways = (dp[j] + left) % MOD;

                    dp[j] = ways;
                    left = ways;
                }
                else {
                    swap(dp[j], left);
                }
            }
        }

        return 0;
    }
};