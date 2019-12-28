class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int vis[m][n];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) cnt++;
            }
            if (cnt > 1) for (int j = 0; j < n; j++) if (grid[i][j]) vis[i][j] = 1;
        }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (grid[j][i]) cnt++;
            }
            if (cnt > 1) for (int j = 0; j < m; j++) if (grid[j][i]) vis[j][i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (vis[i][j]) {
                    ans++;
                    // printf("%d %d\n", i, j);
                }
        return ans;
    }
};
