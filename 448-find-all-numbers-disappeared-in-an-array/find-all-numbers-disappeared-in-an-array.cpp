class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_map<int,int> table;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            table[nums[i]]++;
        }

        for(int i = 1; i <= nums.size(); i++) {
            if(!table.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};