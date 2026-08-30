class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        if(n<3)
            return nums[n-1];

        int large=nums[n-1];
        int count=2;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<large){
                large=nums[i];
                count--;

                if(count==0)
                    return large;
            }
        }

        return nums[n-1];
    }
};