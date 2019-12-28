class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int row=matrix.size();
        const int column=matrix[0].size();
        bool row_has_zero=false;
        bool column_has_zero=false;
        for(int i=0;i<column;i++){
            if(matrix[0][i]==0){
                row_has_zero=true;
                break;
            }
        }
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                column_has_zero=true;
                break;
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(row_has_zero){
            for(int i=0;i<column;i++){
                matrix[0][i]=0;
            }
        }
        if(column_has_zero){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
    }
};
