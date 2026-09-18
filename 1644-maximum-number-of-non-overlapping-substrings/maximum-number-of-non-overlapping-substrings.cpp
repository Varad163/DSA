class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();

        vector<int> first(26,n),last(26,-1);

        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            first[x]=min(first[x],i);
            last[x]=i;
        }

        vector<pair<int,int>> intervals;

        for(int i=0;i<n;i++){
            if(first[s[i]-'a']!=i) continue;

            int l=i;
            int r=last[s[i]-'a'];
            bool ok=true;

            for(int j=l;j<=r;j++){
                int x=s[j]-'a';

                if(first[x]<l){
                    ok=false;
                    break;
                }

                r=max(r,last[x]);
            }

            if(ok)
                intervals.push_back({l,r});
        }

        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });

        vector<string> ans;
        int prev=-1;

        for(auto [l,r]:intervals){
            if(l>prev){
                ans.push_back(s.substr(l,r-l+1));
                prev=r;
            }
        }

        return ans;
    }
};