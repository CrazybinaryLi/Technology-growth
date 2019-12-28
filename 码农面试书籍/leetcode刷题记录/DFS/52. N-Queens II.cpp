class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<int> C(n,-1);//C[i]表示第i行皇后所在的列编号
        dfs(C,res,0);
        return res;
    }

private:
    void dfs(vector<int>& C,int& res,int b){
        const int N=C.size();
        if(b==N){
            res+=1;
            return;
        }
        else{
            for(int i=0;i<N;i++){
                if(check(C,b,i)){
                    C[b]=i;
                    dfs(C,res,b+1);
                    C[b]=-1;
                }
            }
        }
    }

    bool check(vector<int>& C,int& b,int i){
        for(int j=0;j<b;j++){
            if(C[j]==i) return false;
            if(abs(C[j]-i)==abs(j-b)) return false;
        }
        return true;
    }
};
