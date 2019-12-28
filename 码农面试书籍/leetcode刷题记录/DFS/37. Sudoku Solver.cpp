class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

private:
    bool dfs(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        board[i][j]=k+'0';
                        if(check(board,i,j)&&dfs(board)) return true;
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char>>& board,int i,int j){
        for(int c=0;c<9;c++){
            if(c!=j&&board[i][c]==board[i][j]) return false;
        }
        for(int r=0;r<9;r++){
            if(r!=i&&board[r][j]==board[i][j]) return false;
        }
        for(int r=3*(i/3);r<3*(i/3+1);r++){
            for(int c=3*(j/3);c<3*(j/3+1);c++){
                if((r!=i||c!=j)&&board[r][c]==board[i][j]) return false;
            }
        }
        return true;
    }
};
