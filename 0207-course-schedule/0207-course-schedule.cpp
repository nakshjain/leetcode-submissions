class Solution {
private:
    bool dfs(vector<vector<int>>& adjList, int index, vector<int>& visited, vector<int>& curCycle){
        if(index>=adjList.size()) return false;
        visited[index]=1;
        curCycle[index]=1;
        bool check=false;
        for(int i:adjList[index]){
            if(visited[i] && curCycle[i]) return true;
            if(!visited[i] && dfs(adjList, i, visited, curCycle)) return true;
        }
        curCycle[index]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(vector<int> v: prerequisites){
            adjList[v[1]].push_back(v[0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> curCycle(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(adjList, i, visited, curCycle)) return false;
        }
        return true;
    }
};