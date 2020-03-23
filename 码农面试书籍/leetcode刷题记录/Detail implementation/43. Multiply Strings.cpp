class Solution {//竖式乘法
public:
    string multiply(string num1, string num2) {
        string res="";
        const int m=num1.size();
        const int n=num2.size();
        vector<int> vals(m+n);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j,p2=i+j+1,sum=mul+vals[p2];//p2是当前位，p1是高位。
                vals[p1]+=sum/10;
                vals[p2]=sum%10;
            }
        }
        for(auto val:vals){//从高位开始将数字存入res中，跳过先导0。
            if(!res.empty()||val!=0) res.push_back(val+'0');
        }
        return res.empty()?"0":res;
    }
};
