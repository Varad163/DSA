class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=0;
        vector<int>leftsum;
        vector<int> rightsum(nums.size());
        vector<int>ans;
        for(int i=0;i<=nums.size()-1;i++){
            leftsum.push_back(sum);
            sum+=nums[i];
        }
        

        sum = 0;
        for(int i=nums.size()-1;i>=0;i--){
            rightsum[i]=sum;
            sum+=nums[i];
        }  

        int curr=0;
        for(int i=0;i<=nums.size()-1;i++){
            curr=abs(leftsum[i]-rightsum[i]);
            ans.push_back(curr);
        }

        return ans;


        

    }
};