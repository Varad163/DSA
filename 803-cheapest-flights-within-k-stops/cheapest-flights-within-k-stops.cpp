class Solution {
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k) {
        
        vector<vector<pair<int,int>>>adj(n);

        for(auto flight:flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];

            adj[u].push_back({v,w});
        }

        // dist[node][flightsUsed]
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        >pq;

        dist[src][0]=0;
        pq.push({0,src,0});

        while(!pq.empty()){

            auto [distance,node,flightsUsed]=pq.top();
            pq.pop();

            if(node==dst)
                return distance;

            if(flightsUsed==k+1)
                continue;

            for(auto [neighbor,weight]:adj[node]){

                int newDistance=distance+weight;
                int newFlights=flightsUsed+1;

                if(newDistance<dist[neighbor][newFlights]){
                    dist[neighbor][newFlights]=newDistance;

                    pq.push({
                        newDistance,
                        neighbor,
                        newFlights
                    });
                }
            }
        }

        return -1;
    }
};