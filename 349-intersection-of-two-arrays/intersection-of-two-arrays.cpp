class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> table1;
        unordered_map<int,int> table2;

        for(int i =0;i<nums1.size();i++){
            table1[nums1[i]]++;
        }
        for(int i =0;i<nums2.size();i++){
            table2[nums2[i]]++;
        }

        for(auto &it:table1 ){
            if(table2.count(it.first)){
                ans.push_back(it.first);
            }
            
        }

        return ans;


    }
};
