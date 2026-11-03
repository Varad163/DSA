class Solution {
public:
    int minMoves(vector<int>& nums) {
        int great=0;
        for(int i=0;i<nums.size();i++){
            great=max(great,nums[i]);
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=great-nums[i];
        }

        return ans;
    }
};