class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int r=board.size();
        const int c=board[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
            if(dfs(board,visited,word,0,i,j)) return true;
        }
        return false;
    }

private:
    static bool dfs(const vector<vector<char>>& board,vector<vector<bool>>& visited,const string& word,int index,int x,int y){
        if(index==word.size()) return true;
        if(x<0||x>=board.size()||y<0||y>=board[0].size()) return false;
        if(visited[x][y]) return false;
        if(board[x][y]!=word[index]) return false;
        visited[x][y]=true;
        bool ret=dfs(board,visited,word,index+1,x-1,y)||
                 dfs(board,visited,word,index+1,x+1,y)||
                 dfs(board,visited,word,index+1,x,y-1)||
                 dfs(board,visited,word,index+1,x,y+1);
        visited[x][y]=false;
        return ret;
    }
};
