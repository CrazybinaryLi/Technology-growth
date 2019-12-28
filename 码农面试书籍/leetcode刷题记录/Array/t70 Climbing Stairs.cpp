//ì³²¨ÄÇÆõÊıÁĞ
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        long long a=1,b=2;
        for(int i=3;i<=n;i++){
            long long b=temp;
            b=a+b;
            a=temp;
        }
        return b;
    }
};
