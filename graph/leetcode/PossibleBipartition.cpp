class Solution {
private : 
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1); 
    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0; 
            while (!q.empty()) {
                int node = q.front();q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) return false;
                    
                }
            }
        }
    }
    return true;
}
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for (int i=0; i<dislikes.size();i++){
            int u = dislikes[i][0]; 
            int v = dislikes[i][1];
            adj[u].push_back(v); 
            adj[v].push_back(u);
        } 
        return  isBipartite(adj);



        
    }
};