class Solution {//�����ȿ�������������������ֿ�����������ϵķ�����
public:
    int uniquePaths(int m, int n) {
        if(n>m) swap(m,n);
        int c=m-1;
        int r=n-1;
        int t=0;
        long long a=1;
        long long b=1;
        while(t<r){
            a*=(c+r-t);
            b*=t+1;
            t++;
        }
        return a/b;
    }
};
