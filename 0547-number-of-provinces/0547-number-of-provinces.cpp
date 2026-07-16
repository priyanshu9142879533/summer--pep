class Solution {
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        vector<int> vis(n);

        function<void(int)> dfs = [&](int i) {
            vis[i] = 1;
            for (int j = 0; j < n; j++)
                if (a[i][j] && !vis[j]) dfs(j);
        };

        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs(i), ans++;

        return ans;
    }
};