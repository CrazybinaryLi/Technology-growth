class Solution {
public:
    bool isNumeric(char* string)
    {
        //标记符号、小数点、E（e）是否出现过
        bool sign=false,decimal=false,hasE=false;
        for(int i=0;i<strlen(string);i++){
            if(string[i]=='e'||string[i]=='E'){
                if(i==strlen(string)-1) return false;//e后面一定要接数字
                if(hasE) return false;//不能同时出现两个e
                hasE=true;
            }else if(string[i]=='+'||string[i]=='-'){
                //第一次出现+-号，而不是在字符串开头，必须在e之后
                if(i>0&&!sign&&string[i-1]!='e'&&string[i-1]!='E') return false;
                //第二次出现+-号，则必须在e之后
                if(sign&&string[i-1]!='e'&&string[i-1]!='E') return false;
                sign=true;
            }else if(string[i]=='.'){
                //e后面不能接小数点，小数点不能出现两次
                if(hasE||decimal) return false;
                decimal=true;
            }else if(string[i]<'0'||string[i]>'9') return false;//非法字符
        }
        return true;
    }

};
