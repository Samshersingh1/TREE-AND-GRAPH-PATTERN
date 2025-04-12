class Solution {
    public:
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
    
        void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& islandIdGrid, int id, int& area) {
            int n = grid.size();
            islandIdGrid[i][j] = id;
            area++;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1 && islandIdGrid[ni][nj] == 0) {
                    dfs(ni, nj, grid, islandIdGrid, id, area);
                }
            }
        }
    
        int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<vector<int>> islandIdGrid(n, vector<int>(n, 0));
            unordered_map<int, int> islandSize;
    
            int id = 2;  // Start from 2 to distinguish from 0 and 1  we will use id for a particuler cell not (i,j)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && islandIdGrid[i][j] == 0) {
                        int area = 0;
                        dfs(i, j, grid, islandIdGrid, id, area);
                        islandSize[id] = area;
                        id++;
                    }
                }
            }
    
            int maxIsland = 0;
    
            // Try flipping each 0
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        unordered_set<int> neighborIslands;
                        for (int k = 0; k < 4; k++) {
                            int ni = i + dx[k], nj = j + dy[k];
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n && islandIdGrid[ni][nj] != 0) {
                                neighborIslands.insert(islandIdGrid[ni][nj]);
                            }
                        }
    
                        int area = 1;  // Include the flipped cell
                        for (int island : neighborIslands) {
                            area += islandSize[island];
                        }
    
                        maxIsland = max(maxIsland, area);
                    }
                }
            }
    
            // If grid is all 1s
            for (auto& [id, size] : islandSize) {
                maxIsland = max(maxIsland, size);
            }
    
            return maxIsland;
        }
    };
    