class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc, cnt = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if(classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int M = 1 << cnt;
        int states = m*n*(energy+1)*M;

        vector<bool> vis(states, false);
        queue<tuple<int,int,int,int>> q;

        q.push({sr, sc, energy, M-1});

        int start = (((sr*n+sc)*(energy+1)+energy)*M)+(M-1);
        vis[start] = true;

        int moves = 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r,c,e,mask] = q.front();
                q.pop();

                if(mask == 0)
                    return moves;

                if(e == 0)
                    continue;

                for(int k=0; k<4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr<0 || nr>=m || nc<0 || nc>=n)
                        continue;

                    if(classroom[nr][nc] == 'X')
                        continue;

                    int ne = e-1;
                    int nmask = mask;

                    if(classroom[nr][nc] == 'R')
                        ne = energy;

                    if(classroom[nr][nc] == 'L') {
                        nmask &= ~(1 << id[nr][nc]);
                    }

                    int state = (((nr*n+nc)*(energy+1)+ne)*M)+nmask;

                    if(!vis[state]) {
                        vis[state] = true;
                        q.push({nr,nc,ne,nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};