class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        int rbegin=0,rend=matrix.size()-1;//行范围
        int cbegin=0,cend=matrix[0].size()-1;//列范围
        while(true){
            //from left to right
            int j=cbegin;
            while(j++<=cend) ans.push_back(matrix[rbegin][j-1]);
            if(++rbegin>rend) break;
            //from top to bottom
            j=rbegin;
            while(j++<=rend) ans.push_back(matrix[j-1][cend]);
            if(--cend<cbegin) break;
            //from right to left
            j=cend;
            while(j-->=cbegin) ans.push_back(matrix[rend][j+1]);
            if(--rend<rbegin) break;
            //from bottom to top
            j=rend;
            while(j-->=rbegin) ans.push_back(matrix[j+1][cbegin]);
            if(++cbegin>cend) break;
        }
        return ans;
    }
};
