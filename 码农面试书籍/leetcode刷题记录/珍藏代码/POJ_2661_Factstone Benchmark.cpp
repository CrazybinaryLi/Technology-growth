#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "iostream"
using namespace std;
int main(){
    int y,x;
	__int64 k;
	double r;
	while(scanf("%d",&y)&&y!=0){
       x=(y-1960)/10;
	   k=pow(2.0,(int)(x+2));
	   r=0.0;
	   int i=1;
	   while(r<(double)k){
		  i++;
          r+=log((double)i)/log(2.0);
	   }
	   i--;
	   printf("%d\n",i);
	}
	return 0;
}