class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();

        vector<vector<int>> adj(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }

        unordered_map<int,long long> cnt;

        long long ans=0;

        vector<pair<int,int>> st;
        st.push_back({0,0});

        vector<int> mask(n,0);

        while(!st.empty()){
            int u=st.back().first;
            int state=st.back().second;
            st.pop_back();

            if(state==0){
                // count paths ending at u
                ans+=cnt[mask[u]];

                for(int b=0;b<26;b++){
                    ans+=cnt[mask[u]^(1<<b)];
                }

                cnt[mask[u]]++;

                for(int v:adj[u]){
                    mask[v]=mask[u]^(1<<(s[v]-'a'));
                    st.push_back({v,0});
                }
            }
        }

        return ans;
    }
};