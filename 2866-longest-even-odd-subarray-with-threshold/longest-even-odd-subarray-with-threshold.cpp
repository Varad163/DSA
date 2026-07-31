class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] % 2 || nums[i] > threshold) {
                i++;
                continue;
            }

            int j = i;
            while (j + 1 < n &&
                   nums[j + 1] <= threshold &&
                   (nums[j] % 2 != nums[j + 1] % 2)) {
                j++;
            }

            ans = max(ans, j - i + 1);
            i = j + 1;
        }

        return ans;
    }
};