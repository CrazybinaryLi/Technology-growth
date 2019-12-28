class Solution {
public:
    int divide(int dividend, int divisor) {
        //如果是INT_MIN,-INT_MIN会溢出，故要取long long
        long long a=dividend>=0?dividend:-(long long)dividend;
        long long b=divisor>=0?divisor:-(long long)divisor;
        long long result=0;
        while(a>=b){
            long long c=b;
            for(int i=0;a>=c;i++,c<<=1){
                a-=c;
                result+=1<<i;
            }
        }
        //cout<<result<<endl;
        if((dividend^divisor)>>31){
            //如果异号,则结果应该为负数。
            if(result<=(long long)INT_MAX+1) return -result;
            else return INT_MAX;
        }
        else return result<=INT_MAX?result:INT_MAX;
    }
};
