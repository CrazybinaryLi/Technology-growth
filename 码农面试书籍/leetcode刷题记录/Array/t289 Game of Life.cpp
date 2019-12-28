	class Solution {
	public:
	    void gameOfLife(vector<vector<int>>& board) {
			vector<vector<int>> board_copy(board);
			int m=board.size();
			int n=board[0].size();
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					int env_count=0;
					for(int r=i-1;r<=i+1;r++){
						for(int c=j-1;c<=j+1;c++){
							if(r==i&&c==j) continue;
							if(r<0||r>=m||c<0||c>=n) continue;
							if(board_copy[r][c]==1) env_count++;
						}
					}
					if(board[i][j]==1&&(env_count<2||env_count>3)) {
						board[i][j]=0;
						continue;
					}
					if(board[i][j]==0&&env_count==3) board[i][j]=1;
				}
			}
	    }
	};
