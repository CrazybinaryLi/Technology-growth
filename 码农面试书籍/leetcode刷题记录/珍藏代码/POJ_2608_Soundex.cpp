#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
int main(){
	char s[25];
	memset(s,0,sizeof(s));
	while(scanf("%s",s)!=EOF){
		int num[25],k=0;
		memset(num,0,sizeof(num));
		for(int i=0;i<sizeof(s);i++){
			if(i==0) {
				if(s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V') num[k++]=1;
                	if(s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z') num[k++]=2;
						if(s[i]=='D'||s[i]=='T') num[k++]=3;
							if(s[i]=='M'||s[i]=='N') num[k++]=5;
								if(s[i]=='L') num[k++]=4;
									if(s[i]=='R') num[k++]=6;
			}
			else{
				 if((s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V')&&s[i-1]!='B'&&s[i-1]!='F'&&s[i-1]!='P'&&s[i-1]!='V') num[k++]=1;
                	if((s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z')&&s[i-1]!='C'&&s[i-1]!='G'&&s[i-1]!='J'&&s[i-1]!='K'&&s[i-1]!='Q'&&s[i-1]!='S'&&s[i-1]!='X'&&s[i-1]!='Z') num[k++]=2;
						if((s[i]=='D'||s[i]=='T')&&s[i-1]!='D'&&s[i-1]!='T') num[k++]=3;
							if((s[i]=='M'||s[i]=='N')&&s[i-1]!='M'&&s[i-1]!='N') num[k++]=5;
								if((s[i]=='L')&&s[i-1]!='L') num[k++]=4;
									if((s[i]=='R')&&s[i-1]!='R') num[k++]=6;
			}
		}
		for(int j=0;j<k;j++){
			if(num[j]!=0)
			printf("%d",num[j]);
		}
		printf("\n");
		memset(s,0,sizeof(s));
	}
	return 0;
}