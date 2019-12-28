#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int n;
void numSquares(int n) {
	int* dp=new int[n+5];
	for(int i=0;i<=n;i++){
		dp[i]=INT_MAX-5;
	}
	dp[0]=0;
	int m=sqrt(n);
	for(int i=1;i<=m;i++){
		for(int j=i*i;j<=n;j++){
			dp[j]=min(dp[j],dp[j-i*i]+1);
			//printf("%d %d\n",j,dp[j]);
		}
	}
	for(int i=0;i<=n;i++) printf("%d ",dp[i]);
	printf("\n");
}

int main() {
	while(~scanf("%d",&n)) {
		numSquares(n);
	}
	return 0;
}
