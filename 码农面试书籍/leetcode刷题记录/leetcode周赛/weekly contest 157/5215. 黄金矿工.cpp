//dfs走迷宫
class Solution
{
public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        if(grid.size()==0)
            return 0;
        const int row=grid.size();//行数
        const int column=grid[0].size();//列数
        res=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                if(grid[i][j]==0)
                    continue;//如果是0，直接就跳过。
                for(int a=0; a<15; a++)
                {
                    for(int b=0; b<15; b++)
                    {
                        visit[a][b]=false;
                    }
                }
                visit[i][j]=true;//最开始进入的点也要标记啊，真的粗心！
                int tmp=grid[i][j];//中间结果
                dfs(grid,make_pair(i,j),tmp);
            }
        }
        return res;
    }

private:
    int fx[4][2]= {{-1,0},{1,0},{0,-1},{0,1}}; //四个方向
    bool visit[15][15];//标记元素是否已经被访问
    int res;//最终结果
    void dfs(vector<vector<int>>& grid,pair<int,int> st,int y)
    {
        res=max(res,y);
        for(int i=0; i<4; i++)
        {
            int dx=st.first+fx[i][0];
            int dy=st.second+fx[i][1];
            if(0<=dx&&dx<grid.size()&&0<=dy&&dy<grid[0].size()&&!visit[dx][dy]&&grid[dx][dy]!=0)
            {
                //边界不能超，0不能进入，没有被访问。
                visit[dx][dy]=true;
                dfs(grid,make_pair(dx,dy),y+grid[dx][dy]);
                visit[dx][dy]=false;
            }
        }
    }
};
