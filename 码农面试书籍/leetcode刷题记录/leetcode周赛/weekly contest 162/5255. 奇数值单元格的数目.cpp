class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i=0;i<indices.size();i++){
            for(int c=0;c<m;c++) arr[indices[i][0]][c]++;
            for(int r=0;r<n;r++) arr[r][indices[i][1]]++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]%2!=0) cnt++;
            }
        }
        return cnt;
    }
};
