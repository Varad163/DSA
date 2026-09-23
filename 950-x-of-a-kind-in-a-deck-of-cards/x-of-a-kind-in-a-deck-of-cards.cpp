class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        

        unordered_map<int,int> mp;

        for (auto x:deck){
            mp[x]++;
        }

        int g=0;

        for(auto x:mp){
            g=__gcd(g,x.second);
        }

        return g>1;

    }
};