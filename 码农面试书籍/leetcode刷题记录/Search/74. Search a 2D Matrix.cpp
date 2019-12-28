class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int row=matrix.size();
        if(row<=0) return false;
        const int column=matrix[0].size();
        int index_r=0;
        int index_c=column-1;
        while(index_r<row&&index_c>=0){
            if(matrix[index_r][index_c]==target) return true;
            else if(matrix[index_r][index_c]>target) index_c--;
            else index_r++;
        }
        return false;
    }
};
