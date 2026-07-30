class Solution {
private:
    void dfs(vector<vector<int>>& image, int currCol, int i, int j, int color){
        int n= image.size();
        int m=image[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(image[i][j]!=currCol || image[i][j]==color) return;
        image[i][j]=color;
        dfs(image, currCol, i+1, j, color);
        dfs(image, currCol, i-1, j, color);
        dfs(image, currCol, i, j+1, color);
        dfs(image, currCol, i, j-1, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, image[sr][sc], sr, sc, color);
        return image;
    }
};