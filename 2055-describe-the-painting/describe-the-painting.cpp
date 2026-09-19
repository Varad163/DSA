class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> diff;

        for(auto &s:segments){
            diff[s[0]]+=s[2];
            diff[s[1]]-=s[2];
        }

        vector<vector<long long>>ans;

        long long sum=0;
        int prev=-1;

        for(auto &[x,val]:diff){
            if(prev!=-1 && sum>0){
                ans.push_back({prev,x,sum});
            }

            sum+=val;
            prev=x;
        }

        return ans;
    }
};