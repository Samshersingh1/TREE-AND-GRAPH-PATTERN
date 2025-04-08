 

 //we are given a graph or make to graph...

 class Solution {
    public:
        bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
            vis[node] = 1;
            for (auto& neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    if (dfs(neighbor, node, adj, vis))   //here parents will be the latest parent...
                        return true;
                } else if (neighbor != parent) {     
                    return true; // Cycle detected
                }
            }
            return false;
        }
    
        bool isCycle(int V, vector<vector<int>>& edges) {
            vector<vector<int>> adj(V);
            
            // Build adjacency list
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u); // because undirected
            }
    
            vector<int> vis(V, 0);
    
            for (int i = 0; i < V; ++i) {
                if (!vis[i]) {
                    if (dfs(i, -1, adj, vis)) 
                        return true;
                }
            }
    
            return false;
        }
    };
    