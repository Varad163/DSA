class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        vector<vector<int>> adj(edges.size()+2);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<=edges.size()+1;i++) {
            if(adj[i].size()==edges.size()) {
                return i;
            }
        }

        return -1;
    }
};