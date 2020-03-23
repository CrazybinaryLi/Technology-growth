class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        //回溯法(深度优先搜索)经典题
        if(matrix==nullptr||rows<=0||cols<=0||str==nullptr) return false;
        bool* flag=new bool[rows*cols];
        memset(flag,false,rows*cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(matrix,i,j,rows,cols,flag,str,0)) return true;
            }
        }
        delete[] flag;
        return false;
    }

private:
    bool dfs(char* matrix,int i,int j,int rows,int cols,bool* flag,char* str,int k){
        //因为用一维数组存放的二维数组的值，所以index就相当于二维数组在一维数组中的下标。
        int index=i*cols+j;
        //条件检查
        if(i<0||i>=rows||j<0||j>=cols||matrix[index]!=str[k]||flag[index]==true) return false;
        //字符串已经查找结束，返回true。
        if(str[k+1]=='\0') return true;
        //标记已经访问
        flag[index]=true;
        //上下左右四个方向搜索
        if(dfs(matrix,i-1,j,rows,cols,flag,str,k+1)||dfs(matrix,i+1,j,rows,cols,flag,str,k+1)||dfs(matrix,i,j-1,rows,cols,flag,str,k+1)||dfs(matrix,i,j+1,rows,cols,flag,str,k+1))
            return true;
        flag[index]=false;
        return false;
    }
};
