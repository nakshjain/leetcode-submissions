class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i, j}, 0});
            }
        }
        int drow[]={-1, 0, 1, 0};
        int dcol[]={0, -1, 0, 1};
        int time=0;
        while(!q.empty()){
            int count = q.size();
            while(count--){
                int i = q.front().first.first;
                int j = q.front().first.second;
                int curTime = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int row=i+drow[k];
                    int col=j+dcol[k];
                    if(row<n && row>=0 && col<m && col>=0 && grid[row][col]==1){
                        q.push({{row, col}, curTime+1});
                        grid[row][col]=2;
                    }
                }
                time=curTime;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};