class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        vector<vector<int>> graph(n,vector<int>(n,0));

        for(auto road:roads){
            degree[road[0]]++;
            degree[road[1]]++;
            
            graph[road[0]][road[1]]=1;
            graph[road[1]][road[0]]=1;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int rank=degree[i]+degree[j];

                if(graph[i][j]){
                    rank--;
                }

                ans=max(ans,rank);
            }
        }

        return ans;
    }
};