class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> g(n + 1);
        for (auto &e : d)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        vector<int> c(n + 1, -1);

        function<bool(int,int)> dfs = [&](int u, int col) {
            c[u] = col;
            for (int v : g[u]) {
                if (c[v] == -1) {
                    if (!dfs(v, col ^ 1)) return false;
                } else if (c[v] == col) return false;
            }
            return true;
        };

        for (int i = 1; i <= n; i++)
            if (c[i] == -1 && !dfs(i, 0)) return false;

        return true;
    }
};