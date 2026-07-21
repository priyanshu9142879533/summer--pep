class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        function<long long(int)> dfs = [&](int u) {
            vis[u] = 1;
            long long cnt = 1;
            for (int v : g[u])
                if (!vis[v]) cnt += dfs(v);
            return cnt;
        };

        long long ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long sz = dfs(i);
                ans += sz * sum;
                sum += sz;
            }
        }
        return ans;
    }
};