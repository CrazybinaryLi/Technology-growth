class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {//考虑每个数位上出现1的次数,每个数位上出现1的次数由更高位跟低位决定。
        int higher=0,lower=0;
        int count=0;
        int bit=1;//计数单位
        while(n){
            int cur=n%10;//当前位上的数
            higher=n/10;
            if(cur==0){
                //如果当前位数为0，则当前位上1的个数由更高位决定
                count+=higher*bit;
            }else if(cur==1){
                //如果当前位数为1，则当前位上1的个数由更高位和更低位决定
                count+=higher*bit+(lower+1);
            }else{
                //如果当前位数大于1，则当前位上1的个数由更高位决定
                count+=(higher+1)*bit;
            }
            n/=10;
            lower=cur*bit+lower;
            bit*=10;
        }
        return count;
    }
};
