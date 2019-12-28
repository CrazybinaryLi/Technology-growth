class Solution {//模拟题
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        int beginX=0,endX=matrix[0].size()-1;//列
        int beginY=0,endY=matrix.size()-1;//行
        while(true){
            //从左到右
            for(int j=beginX;j<=endX;j++) ans.push_back(matrix[beginY][j]);
            if(++beginY>endY) break;
            //从上到下
            for(int i=beginY;i<=endY;i++) ans.push_back(matrix[i][endX]);
            if(beginX>--endX) break;
            //从右到左
            for(int j=endX;j>=beginX;j--) ans.push_back(matrix[endY][j]);
            if(beginY>--endY) break;
            //从下到上
            for(int i=endY;i>=beginY;i--) ans.push_back(matrix[i][beginX]);
            if(++beginX>endX) break;
        }
        return ans;
    }
};
