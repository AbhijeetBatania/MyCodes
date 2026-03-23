class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int u, vector<int>& result, vector<bool>& visited){
        if(visited[u]) return;
        
        visited[u] = true;
        result.push_back(u);
        
        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, result, visited);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> result;
        vector<bool> visited(adj.size() , false);
        
        DFS(adj , 0 , result, visited);
        return result;
    }
};
