class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int cnt = 0;
        int maxi = 0;

        for (int x : nums) {
            if (x == 1) {
                cnt++;
                maxi = max(maxi, cnt);
            } else {
                cnt = 0;
            }
        }

        return maxi;
    }
};