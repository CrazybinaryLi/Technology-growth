class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //模式匹配的题用递归可以减少代码量
        if(*str=='\0'&&*pattern=='\0') return true;
        else if(*str!='\0'&&*pattern=='\0') return false;
        //if next character in pattern is not '*'
        if(*(pattern+1)!='*'){
            if(*str==*pattern||(*str!='\0'&&*pattern=='.')) return match(str+1,pattern+1);
            else return false;
        }
        //if next character in pattern is '*'
        if(*(pattern+1)=='*'){
            if(*str==*pattern||(*str!='\0'&&*pattern=='.')) return match(str+1,pattern)||match(str,pattern+2);
            else return match(str,pattern+2);
        }
    }
};
