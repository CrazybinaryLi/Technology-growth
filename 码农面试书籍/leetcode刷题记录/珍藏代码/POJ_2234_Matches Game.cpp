#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int m;
	while(scanf("%d",&m)!=EOF){
		__int64 a=0,b;
		while(m--){
			scanf("%I64d",&b);
			a^=b;
		}
		if(a!=0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}