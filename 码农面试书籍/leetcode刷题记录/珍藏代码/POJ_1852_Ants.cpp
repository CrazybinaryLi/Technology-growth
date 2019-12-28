#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "algorithm"
using namespace std;
int a[1000001];
int main(){
	int n;
    scanf("%d",&n);
	while(n--){
		int s,num;
		memset(a,0,sizeof(a));
	    scanf("%d %d",&s,&num);
		int m=-1,M=-1;
        for(int i=0;i<num;i++){
			scanf("%d",&a[i]);
			if(s-a[i]>a[i]){
				if(s-a[i]>=M) M=s-a[i];
				if(a[i]>=m) m=a[i];
			}
			else if(a[i]>=s-a[i]){
				if(a[i]>=M) M=a[i];
				if(s-a[i]>=m) m=s-a[i];
			}
        }
		printf("%d %d\n",m,M);
	}
	return 0;
}
