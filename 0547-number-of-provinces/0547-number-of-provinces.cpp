class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjGraph(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjGraph[i].push_back(j);
                    adjGraph[j].push_back(i);
                }
            }
        }
        vector<int> visited(isConnected.size(), 0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                count++;
                dfs(adjGraph, visited, i);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& adjGraph, vector<int>& visited, int node){
        visited[node]=1;
        for(int i=0;i<adjGraph[node].size();i++){
            if(!visited[adjGraph[node][i]]) dfs(adjGraph, visited, adjGraph[node][i]);
        }
    }
};