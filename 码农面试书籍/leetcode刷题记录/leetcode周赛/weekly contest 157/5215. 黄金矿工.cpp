//dfs���Թ�
class Solution
{
public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        if(grid.size()==0)
            return 0;
        const int row=grid.size();//����
        const int column=grid[0].size();//����
        res=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                if(grid[i][j]==0)
                    continue;//�����0��ֱ�Ӿ�������
                for(int a=0; a<15; a++)
                {
                    for(int b=0; b<15; b++)
                    {
                        visit[a][b]=false;
                    }
                }
                visit[i][j]=true;//�ʼ����ĵ�ҲҪ��ǰ�����Ĵ��ģ�
                int tmp=grid[i][j];//�м���
                dfs(grid,make_pair(i,j),tmp);
            }
        }
        return res;
    }

private:
    int fx[4][2]= {{-1,0},{1,0},{0,-1},{0,1}}; //�ĸ�����
    bool visit[15][15];//���Ԫ���Ƿ��Ѿ�������
    int res;//���ս��
    void dfs(vector<vector<int>>& grid,pair<int,int> st,int y)
    {
        res=max(res,y);
        for(int i=0; i<4; i++)
        {
            int dx=st.first+fx[i][0];
            int dy=st.second+fx[i][1];
            if(0<=dx&&dx<grid.size()&&0<=dy&&dy<grid[0].size()&&!visit[dx][dy]&&grid[dx][dy]!=0)
            {
                //�߽粻�ܳ���0���ܽ��룬û�б����ʡ�
                visit[dx][dy]=true;
                dfs(grid,make_pair(dx,dy),y+grid[dx][dy]);
                visit[dx][dy]=false;
            }
        }
    }
};
