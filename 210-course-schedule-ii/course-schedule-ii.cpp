class Solution {
public:
    vector<int> toposort(int n,vector<vector<int>>& adj){
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto neighbour:adj[i]){
                indegree[neighbour]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);

            for(auto neighbour:adj[node]){
                indegree[neighbour]--;

                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        if(ans.size()!=n){
            return {};
        }

        return ans;
    }

    vector<int> findOrder(int numCourses,vector<vector<int>>& prerequisites){

        vector<vector<int>> adj(numCourses);

        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];

            adj[v].push_back(u);
        }

        return toposort(numCourses,adj);
    }
};