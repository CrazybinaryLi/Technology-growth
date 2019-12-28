//容斥原理配合二分查找
class Solution {
public:
    long long nthUglyNumber(long long n, long long a, long long b, long long c) {
        long long ab=lcm(a,b);
        long long ac=lcm(a,c);
        long long bc=lcm(b,c);
        long long abc=lcm(ab,c);
        long long left=1;
        long long right=2000000001;
        while(left<right){
            long long mid=(left+right)/2;
            long long r=mid/a+mid/b+mid/c-(mid/ab)-(mid/ac)-(mid/bc)+(mid/abc);
            if(r>=n) right=mid;
            else{
                left=mid+1;
            }
        }
        return left;
    }

private:
    long long gcd(long long a,long long b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }

    long long lcm(long long a,long long b){
        return a*b/gcd(a,b);
    }

};
