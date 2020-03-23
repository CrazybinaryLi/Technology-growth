class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()<1) return false;
        int row=array.size();
        int col=array[0].size();
        int x=0,y=col-1;
        while(x<row&&y>=0){
            if(array[x][y]==target) return true;
            if(array[x][y]<target) x++;
            else y--;
        }
        return false;
    }
};
