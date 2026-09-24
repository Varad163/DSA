class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(auto x:arr){
            mp[x]++;
        }

        sort(arr.begin(),arr.end(), [](int a,int b){
            return abs(a)<abs(b);
        });

        for(auto x:arr){

            if(mp[x]==0){
                continue;
            }

            if(x==0){
                if(mp[x]%2!=0)
                    return false;
            
            mp[x]=0;
            continue;
            }

            if(mp[2*x]==0)
                return false;

            mp[x]--;
            mp[2*x]--;
        }

        return true;
    }
};