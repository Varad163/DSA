class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int> mp(nums.size()/2+2);
        
        for(auto x:nums){
            mp[x]++;


        }

        for(auto x:mp){
            if(x.second==n)
                return x.first;
        }
        return -1;
    }
};