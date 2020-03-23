class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        //约瑟夫环问题，关键是数学公式的递推。
        if(n==0||m<=0) return -1;
        vector<int> f(n+1,0);
        for(int i=2;i<=n;i++){
            f[i]=(f[i-1]+m)%i;
        }
        return f[n];
    }
};
