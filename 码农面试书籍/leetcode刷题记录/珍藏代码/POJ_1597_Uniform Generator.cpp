#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
#include "cmath"
using namespace std;
int a[100005];
int main(){
	int STEP,MOD;
	while(scanf("%d %d",&STEP,&MOD)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=0;i<MOD-1;i++){
			a[i+1]=(a[i]+STEP)%MOD;
		}
        sort(a,a+MOD);
		int flag=true;
		for(int j=0;j<MOD;j++){
			if(a[j]!=a[j+1]) continue;
			else flag=false;
		}
		if(flag) printf("%10d%10d    Good Choice\n\n",STEP,MOD);
		if(!flag) printf("%10d%10d    Bad Choice\n\n",STEP,MOD);
	}
	return 0;
}