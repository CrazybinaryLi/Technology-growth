class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int row=board.size();
        if(row==0) return;
        const int column=board[0].size();
        for(int j=0;j<column;j++){//上下边界
            if(board[0][j]=='O'){
                bfs(0,j,board);
            }
            if(board[row-1][j]=='O'){
                bfs(row-1,j,board);
            }
        }
        for(int i=1;i<board.size()-1;i++){
            if(board[i][0]=='O'){
                bfs(i,0,board);
            }
            if(board[i][column-1]=='O'){
                bfs(i,column-1,board);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='*') board[i][j]='O';
            }
        }
    }

private:
    void bfs(int x,int y,vector<vector<char>>& board){
        vector<vector<bool>> visit(board.size());
        for(int i=0;i<board.size();i++) visit[i].resize(board[0].size());
        for(int i=0;i<visit.size();i++){
            for(int j=0;j<visit[0].size();j++){
                visit[i][j]=false;
            }
        }
        int fx[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
        queue<pair<int,int>> q{{make_pair(x,y)}};
        visit[x][y]=true;
        while(!q.empty()){
            pair<int,int> tp=q.front();
            q.pop();
            board[tp.first][tp.second]='*';
            for(int i=0;i<4;i++){
                int tx=tp.first+fx[i][0];
                int ty=tp.second+fx[i][1];
                if(0<=tx&&tx<board.size()&&0<=ty&&ty<board[0].size()&&board[tx][ty]=='O'&&!visit[tx][ty]){
                    visit[tx][ty]=true;
                    q.push({tx,ty});
                }
            }
        }
    }
};
