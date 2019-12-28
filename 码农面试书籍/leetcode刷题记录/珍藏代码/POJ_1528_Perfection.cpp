#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "algorithm"
#include "cmath"
#include "cstring"
using namespace std;
int Fenjie(int n){
	int sum=1;
	for(int i=2;i<=(int)sqrt((double)n);i++){
		if(n%i==0) {
			sum=sum+i+(n/i);
		}
		else continue;
	}
	if((int)sqrt((double)n)*(int)sqrt((double)n)==n) sum-=(int)sqrt((double)n);
	return sum;
}
int main(){
    int a[105],n,k,i=0;
	memset(a,0,sizeof(a));
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		else a[i++]=n;
		k=i;
	}
	printf("PERFECTION OUTPUT\n");
    for(int j=0;j<k;j++){
		if(Fenjie(a[j])==a[j]) printf("%5d  PERFECT\n",a[j]);
		if(Fenjie(a[j])>a[j])  printf("%5d  ABUNDANT\n",a[j]);
		if(Fenjie(a[j])<a[j])  printf("%5d  DEFICIENT\n",a[j]);
    }
	printf("END OF OUTPUT\n");
	return 0;
}