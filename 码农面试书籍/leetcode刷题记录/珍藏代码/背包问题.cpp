#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int f[105],V;
void zeroonepack(int cost,int weight) {

    for(int v=V; v>=cost; v--) {
        f[v]=max(f[v],f[v-cost]+weight);
    }
}
void completepack(int cost,int weight) {
    for(int v=cost; v<=V; v++) {
        f[v]=max(f[v],f[v-cost]+weight);
    }
}
void multipelepack(int cost,int weight,int amount) {
    if(amount*cost>=V) {
        completepack(cost,weight);
        return;
    }
    for(int k=1; k<amount; k*=2) {
        zeroonepack(k*cost,k*weight);
        amount=amount-k;
    }
    zeroonepack(amount*cost,amount*weight);
}
int main() {
    int t,i,n,cost,weight,amount;
    scanf("%d",&t);
    while(t--) {
        memset(f,0,sizeof(f));
        scanf("%d%d",&V,&n);
        for(i=1; i<=n; i++) {
            scanf("%d%d%d",&cost,&weight,&amount);
            multipelepack(cost,weight,amount);
        }
        printf("%d\n",f[V]);
    }

    return 0;
}
