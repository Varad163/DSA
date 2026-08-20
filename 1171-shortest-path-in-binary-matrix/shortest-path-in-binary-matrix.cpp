class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return -1;

        vector<int> sr={1,1,1,-1,-1,-1,0,0};
        vector<int> sc={-1,0,1,-1,0,1,-1,1};

        queue<pair<pair<int,int>,int>>q;

        q.push({{0,0},1});
        grid[0][0]=1;


        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;

            q.pop();

            if(r==n-1 && c==n-1)
            return dist;

            for(int i=0;i<8;i++){
                int nr=r+sr[i];
                int nc=c+sc[i];

                if(nr<0||nr>=n||nc<0||nc>=n||grid[nr][nc]==1)
                continue;

                grid[nr][nc]=1;
                q.push({{nr,nc},dist+1});

            }
        }
        return -1;
    }
};