class Solution {
private:
    int n = 0;
    int m = 0;
    const int drows[4] = {-1, 0, 1, 0};
    const int dcols[4] = {0, -1, 0, 1};

    void dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int row = i + drows[k];
            int col = j + dcols[k];
            if(row>=0 && row<n &&
                col>=0 && col<m &&
                grid[row][col]) dfs(grid, row, col);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]){
                    dfs(grid, i, j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) count++;
            }
        }
        return count;
    }
};