class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min = *min_element(nums1.begin(), nums1.end());
        for(int x:nums1){
            if(x%2!=0 && min%2==0)
                return false;
        }

        return true;
    }
};