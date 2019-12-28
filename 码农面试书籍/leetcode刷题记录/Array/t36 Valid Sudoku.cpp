class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        //判断每一行有没有相同的元素
        //判断每一列有没有相同的元素
        //判断每一个3*3的小正方形内有没有相同的元素
        bool used[9]={false};
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.') continue;
                if(used[board[i][j]-'1']==true) return false;
                else used[board[i][j]-'1']=true;
            }
            fill(used,used+9,false);
        }
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[j][i]=='.') continue;
                if(used[board[j][i]-'1']==true) return false;
                else used[board[j][i]-'1']=true;
            }
            fill(used,used+9,false);
        }
        map<char,int> square;
        int dir[9][2]= {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=1; i<=7; i+=3)
        {
            for(int j=1; j<=7; j+=3)
            {
                for(int k=0; k<9; k++)
                {
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(board[x][y]=='.') continue;
                    if(used[board[x][y]-'1']==true) return false;
                    else used[board[x][y]-'1']=true;
                }
                fill(used,used+9,false);
            }
        }
        return true;
    }
};
