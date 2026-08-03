class Solution {
private:
    bool check(vector<vector<int>>& graph, vector<int>& color, int node){
        queue<int> q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(const int neighbor: graph[front]){
                if(color[neighbor]==-1){
                    color[neighbor]=!color[front];
                    q.push(neighbor);
                } else if (color[neighbor]==color[front]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !check(graph, color, i)) return false;
        }
        return true;
    }
};