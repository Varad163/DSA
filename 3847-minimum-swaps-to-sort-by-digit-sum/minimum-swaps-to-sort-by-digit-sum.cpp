class Solution {
public:
    int sum(int x){
        int s=0;
        while (x){
            s+=x%10;
            x/=10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums){
        int n=nums.size();

        vector<pair<int,int>> a;

        for(int i=0;i<n;i++)
            a.push_back({nums[i],i});

        sort(a.begin(),a.end(),[&](auto x,auto y){
            if(sum(x.first)!=sum(y.first))
                return sum(x.first)<sum(y.first);
            return x.first<y.first;
        });

        vector<int> p(n);
        for(int i=0;i<n;i++)
            p[a[i].second]=i;

        vector<bool> vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(vis[i]||p[i]==i) continue;

            int j=i,cnt=0;
            while(!vis[j]){
                vis[j]=true;
                j=p[j];
                cnt++;
            }
            ans+=cnt-1;
        }

        return ans;
    }
};