#include "cstring"
#include "cstdlib"
#include "iostream"
#include "algorithm"
using namespace std;
int a[111111];
int main(){
	int n;
    scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
            scanf("%d",a+i);
		}
		if(n==1){
			printf("%d\n%d\n",a[1],a[1]);
			return 0;
		}
		int nn=n;
		sort(a+1,a+1+n);
		while(n>3){
            if(2*a[1]+a[n]+a[n-1]<2*a[2]+a[1]+a[n]){
               ans+=a[n]+a[1]+a[n-1]+a[1];
            }
			else {
				ans+=a[2]+a[1]+a[n]+a[2];
			}
			n-=2;
		}
		if(n==2) ans+=a[2];
		else ans+=a[1]+a[2]+a[3];
		printf("%d\n",ans);
		n=nn;
		while(n>3){
           if(a[1]+a[n-1]<2*a[2]){
               printf("%d %d\n%d\n%d %d\n%d\n",a[1],a[n],a[1],a[1],a[n-1],a[1]);
            }
		   else  printf("%d %d\n%d\n%d %d\n%d\n",a[1],a[2],a[1],a[n-1],a[n],a[2]);
		   n-=2;
		}
		if(n==2) printf("%d %d\n",a[1],a[2]);
		else printf("%d %d\n%d\n%d %d\n",a[1],a[3],a[1],a[1],a[2]);
	return 0;
}