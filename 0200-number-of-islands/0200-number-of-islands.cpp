class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size(), ans = 0;

        function<void(int,int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n || g[i][j] == '0') return;
            g[i][j] = '0';
            dfs(i+1,j), dfs(i-1,j), dfs(i,j+1), dfs(i,j-1);
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == '1') dfs(i,j), ans++;

        return ans;
    }
};