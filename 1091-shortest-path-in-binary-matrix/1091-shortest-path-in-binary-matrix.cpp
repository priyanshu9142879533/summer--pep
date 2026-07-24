class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        int d[8][2] = {{1,0},{-1,0},{0,1},{0,-1},
                       {1,1},{1,-1},{-1,1},{-1,-1}};

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if (x == n-1 && y == n-1) return grid[x][y];

            for (auto &k : d) {
                int nx = x + k[0], ny = y + k[1];
                if (nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};