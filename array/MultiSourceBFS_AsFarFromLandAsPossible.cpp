class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size() ;
        queue<pair<int,int>> q;
		// Go in reverse direction, go from land to water
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++)
                if (grid[i][j]==1)	// Insert multiple source at the same time, the next elements dist will depend only upon the current box
                    q.push({i,j}) ;
        }

        int ans = -1;
        int arr[4][2] = {{0,1},{0,-1},{1,0},{-1,0}} ;

        while (!q.empty()){
            auto p = q.front(); q.pop() ;
            int x = p.first , y=p.second;

            for (auto [dx,dy] : arr){
                int nx=x+dx , ny=y+dy ;
                if (min(nx,ny)<0 || max(nx,ny)>=n) continue;

                if (grid[nx][ny]==0){
                    grid[nx][ny] = grid[x][y] + 1 ;
                    ans=max(ans,grid[nx][ny]) ;
                    q.push({nx,ny}) ;
                }
            }
        }

        if (ans==-1) return -1;
        return ans-1;
    }
};
