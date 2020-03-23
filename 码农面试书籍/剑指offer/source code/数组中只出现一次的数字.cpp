class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) {
        //利用位运算中异或的性质，相同为0，不同为1。如果数组只有一个数字是单的
        //将所有数字跟0异或以后，剩下的一定是这个落单的数字。
        //现在有两个落单的数字，数组中所有数字跟0异或以后剩下的数字一定不为0，
        //这个数字对应的二进制表示为1的位就是这两个落单的数字对应二进制位不同的位。
        //以第一个为1的位为分界线将原来数组中所有的数字分成两组，再分别与0异或运算。
        //注意位运算的优先级最低，所以得加括号。
        if(data.size()==2){
            *num1=data[0];
            *num2=data[1];
            return;
        }
        int bitResult=0;
        for(int i=0;i<data.size();i++){
            bitResult^=data[i];
        }
        int index=findFirst1(bitResult);
        int k1=0;
        int k2=0;
        for(int i=0;i<data.size();i++){
            if(isBit1(data[i],index)) k1^=data[i];
            else k2^=data[i];
        }
        *num1=k1;
        *num2=k2;
    }

private:
    int findFirst1(int bitResult){//找到bitResult从右往左起第一个为1的位。
        int index=0;
        while(((bitResult&0x1)==0)&&index<32){
            bitResult>>=1;
            index++;
        }
        return index;
    }

    bool isBit1(int num,int index){
        //判断num的二进制表示第index位是否为1
        while(index--) num>>=1;
        return ((num&0x1)==1)?true:false;
    }
};
