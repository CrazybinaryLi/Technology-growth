class Solution {
public:
    int StrToInt(string str) {
        if(str.size()<1||(str.size()==1&&str[0]=='0')) return 0;
        bool neg=false;//标记是否为负数
        if(str[0]=='-') neg=true;
        long long res=0;
        long long bit=1;
        for(int i=str.size()-1;i>=0;i--){
            if(i==0&&(str[0]=='+'||str[0]=='-')) break;
            if(str[i]>'9'||str[i]<'0') return 0;//非法字符串
            res+=bit*(str[i]-'0');
            bit*=10;
        }
        if(neg&&res-1>INT_MAX) return 0;
        else if(!neg&&res>INT_MAX) return 0;
        return neg?-res:res;
    }
};
