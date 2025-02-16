#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubsets(vector<int> &arr, int n, int xorSum, int k, vector<unordered_map<int, int>> &dp)
{
    if (n == 0)
        return (xorSum == k) ? 1 : 0;

    if (dp[n].find(xorSum) != dp[n].end())
        return dp[n][xorSum];

    // Include current element in XOR sum././.
    int include = countSubsets(arr, n - 1, xorSum ^ arr[n - 1], k, dp);

    // Exclude current element
    int exclude = countSubsets(arr, n - 1, xorSum, k, dp);

    return dp[n][xorSum] = include + exclude;
}

int main()
{
    vector<int> arr = {4, 2, 7, 6, 1};
    int k = 6;

    int n = arr.size();
    vector<unordered_map<int, int>> dp(n + 1);

    cout << "Number of subsets with XOR sum " << k << " = " << countSubsets(arr, n, 0, k, dp) << endl;

    return 0;
}
