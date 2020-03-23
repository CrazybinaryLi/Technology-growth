//数学题
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n=matrix[0].size();
        for(int i=0;i<n;i++){//沿着副对角线翻转
            for(int j=0;j<n-i;j++){
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        for(int i=0;i<n/2;i++){//沿着中轴线翻转
            for(int j=0;j<n;j++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    }
};
