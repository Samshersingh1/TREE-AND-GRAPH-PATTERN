class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParents(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParents(parent[node]);
    }

    void unionByrank(int u, int v) {
        int ult_u = findParents(u);
        int ult_v = findParents(v);
        if(ult_u == ult_v) return;

        if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        } else if(rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        } else {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
};

bool isvalid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q) {
    DisjointSet ds(n * m);
    vector<int> ans;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for(auto &it : q) {
        int row = it[0], col = it[1];

        if(vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        int a = row * m + col;

        for(int i = 0; i < 4; i++) {
            int newx = row + dx[i];
            int newy = col + dy[i];

            if(isvalid(newx, newy, n, m) && vis[newx][newy] == 1) {
                int b = newx * m + newy;
                if(ds.findParents(a) != ds.findParents(b)) {
                    cnt--;
                    ds.unionByrank(a, b);
                }
            }
        }

        ans.push_back(cnt); // push once per query
    }

    return ans;
}
