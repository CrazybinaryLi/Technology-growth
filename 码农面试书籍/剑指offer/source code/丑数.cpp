class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        int* UglyNumber=new int[index];
        UglyNumber[0]=1;//第一个丑数是1
        int nextUglyIndex=1;//接下来的一个丑数的指标
        int* UglyIndex2=UglyNumber;
        int* UglyIndex3=UglyNumber;
        int* UglyIndex5=UglyNumber;
        while(nextUglyIndex++<index){
            int m=min(*UglyIndex2*2,min(*UglyIndex3*3,*UglyIndex5*5));
            UglyNumber[nextUglyIndex-1]=m;
            while(*UglyIndex2*2<=UglyNumber[nextUglyIndex-1]) UglyIndex2++;
            while(*UglyIndex3*3<=UglyNumber[nextUglyIndex-1]) UglyIndex3++;
            while(*UglyIndex5*5<=UglyNumber[nextUglyIndex-1]) UglyIndex5++;
        }
        return UglyNumber[index-1];
    }
};
