class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int beginX=0,endX=n-1;//列
        int beginY=0,endY=n-1;//行
        int count=1;
        while(true){
            //从左到右
            for(int j=beginX;j<=endX;j++,count++) ans[beginY][j]=count;
            if(++beginY>endY) break;
            //从上到下
            for(int i=beginY;i<=endY;i++,count++) ans[i][endX]=count;
            if(beginX>--endX) break;
            //从右到左
            for(int j=endX;j>=beginX;j--,count++) ans[endY][j]=count;
            if(beginY>--endY) break;
            //从下到上
            for(int i=endY;i>=beginY;i--,count++) ans[i][beginX]=count;
            if(++beginX>endX) break;
        }
        return ans;
    }
};
