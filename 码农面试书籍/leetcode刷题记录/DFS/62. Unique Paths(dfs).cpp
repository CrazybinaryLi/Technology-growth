class Solution {//�����ȿ�������������������ֿ�����������ϵķ�����
public:
    int uniquePaths(int m, int n) {
        f=vector<vector<int>> (m,vector<int>(n,0));
        f[0][0]=1;//f[x][y]��ʾ(0,0)->(x,y)��·������,f[x][y]�洢�м���̣������˺ܶ��ظ����㡣
        return dfs(m-1,n-1);
    }

private:
    vector<vector<int>> f;
    int dfs(int c,int r){
        if(c==0||r==0) return 1;
        if(f[c][r]>0) return f[c][r];
        else{
            return f[c][r]=dfs(c-1,r)+dfs(c,r-1);
        }
    }
};
