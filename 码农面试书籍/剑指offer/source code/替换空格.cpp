class Solution {
public:
	void replaceSpace(char *str,int length) {//C类型的指针也可以用数组的方式读取
        if(str==nullptr||length<1) return;
        int count=0;
        for(int i=0;i<length;i++){//从前往后统计空格数
            if(str[i]==' ') count++;
        }
        for(int i=length-1;i>=0;i--){//从后往前移动字符
            if(str[i]!=' '){
                str[i+2*count]=str[i];
            }else{
                count--;
                str[i+2*count]='%';
                str[i+2*count+1]='2';
                str[i+2*count+2]='0';
            }
        }
	}
};
