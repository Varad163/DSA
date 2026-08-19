class Solution {
public:

    bool bfs(int src,int target,vector<vector<int>>& adj){
        queue<int> q;
        vector<int>visited(adj.size(),0);

        q.push(src);
        visited[src]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            if(node==target){
                return true;
            }

            for(int neighbour:adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
            }

        }
        return false;


    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<vector<int>> adj(n+1);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(bfs(u,v,adj)){
                return {u,v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};