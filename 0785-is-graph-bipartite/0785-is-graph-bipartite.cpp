class Solution {
private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& color, int index, int curColor){
        for(int i: graph[index]){
            if(color[i]==-1){
                color[i]=!curColor;
                if(!dfs(graph, color, i, !curColor)) return false;
            } else if (color[i]==curColor) return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(graph, color, i, 0)) return false; 
            }
        }
        return true;
    }
};