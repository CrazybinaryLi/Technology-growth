class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        this->grid=grid;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            dfs(i,0);
            dfs(i,m-1);
        }
        for(int j=0;j<m;j++){
            dfs(0,j);
            dfs(n-1,j);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(this->grid[i][j]==0){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    vector<vector<int>> grid;
    int n,m;
    void dfs(int x,int y){
        if(x<0||x>=n||y<0||y>=m) return;
        if(grid[x][y]!=0) return;
        grid[x][y]=1;
        int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
        for(int i=0;i<4;i++){
            dfs(x+dir[i][0],y+dir[i][1]);
        }
    }
};
