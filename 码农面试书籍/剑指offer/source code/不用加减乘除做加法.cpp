class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum,carry;
        do{
            sum=num1^num2;//异或运算求不进位
            carry=((num1&num2)<<1);//按位与向左移一位是进位。
            num1=sum;
            num2=carry;
        }while(num2!=0);
        return num1;
    }
};
