class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int count=0;


        for(auto x:nums){
            if(x==0){
                continue;
            }

            mp[x]++;

            if(mp[x]==1){
                count++;
            }
        }
        return count;
    }
};