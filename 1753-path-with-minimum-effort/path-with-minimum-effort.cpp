class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows=heights.size();
        int cols=heights[0].size();

        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        >pq;

        dist[0][0]=0;
        pq.push({0,0,0});

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!pq.empty()){

            auto [effort,r,c]=pq.top();
            pq.pop();

            if(r==rows-1&&c==cols-1)
                return effort;

            if(effort>dist[r][c])
                continue;

            for(int i=0;i<4;i++){

                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0||nr>=rows||nc<0||nc>=cols)
                    continue;

                int edgeEffort=abs(heights[r][c]-heights[nr][nc]);

                int newEffort=max(effort,edgeEffort);

                if(newEffort<dist[nr][nc]){
                    dist[nr][nc]=newEffort;

                    pq.push({newEffort,nr,nc});
                }
            }
        }

        return 0;
    }
};