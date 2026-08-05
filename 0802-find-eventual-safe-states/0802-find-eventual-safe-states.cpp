class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& safe, vector<int>& visited, int index){
        if(visited[index]) return safe[index]==1;
        bool isSafe=true;
        visited[index]=1;
        for(int i=0;i<graph[index].size();i++){
            isSafe = isSafe && dfs(graph, safe, visited, graph[index][i]);
            if(!isSafe) return isSafe;
        }
        safe[index]=1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safe(n, 0), visited(n, 0);
        for(int i=0;i<n;i++){
            if(graph[i].size()==0){
                safe[i]=1;
                visited[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]) dfs(graph, safe, visited, i);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};