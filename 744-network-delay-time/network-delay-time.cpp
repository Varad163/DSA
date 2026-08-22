class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times,int n,int k) {
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            graph[u].push_back({v,w});
        }

        vector<int> time(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        time[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();

            if(t>time[node])
                continue;

            for(auto [nextNode,weight]:graph[node]){
                int newTime=t+weight;

                if(newTime<time[nextNode]){
                    time[nextNode]=newTime;
                    pq.push({newTime,nextNode});
                }
            }
        }

        int ans=0;

        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX)
                return -1;

            ans=max(ans,time[i]);
        }

        return ans;
    }
};