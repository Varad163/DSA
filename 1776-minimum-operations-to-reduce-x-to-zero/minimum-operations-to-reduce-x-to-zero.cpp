class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;

        for(int x:nums){
            total+=x;
        }

        int target=total-x;

        if(target<0){
            return -1;
        }

        if(target==0){
            return n;
        }

        int l=0,sum=0;
        int len=-1;

        for(int r=0;r<n;r++){
            sum+=nums[r];

            while(l<=r && sum>target){
                sum-=nums[l];
                l++;
            }

            if(sum==target){
                len=max(len,r-l+1);
            }
        }

        if(len==-1){
            return -1;
        }

        return n-len;  
    }
};