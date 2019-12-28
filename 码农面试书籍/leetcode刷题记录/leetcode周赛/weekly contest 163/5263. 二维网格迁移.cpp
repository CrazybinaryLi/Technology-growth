class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        const int n=grid.size();
        const int m=grid[0].size();
        for(int i=0; i<k; i++)
        {
            for(int j=m-2; j>=0; j--)
            {
                for(int r=0; r<n; r++)
                {
                    swap(grid[r][j],grid[r][j+1]);
                }
            }
            for(int r=n-2;r>=0;r--){
                swap(grid[r][0],grid[r+1][0]);
            }
        }
        return grid;
    }
};
