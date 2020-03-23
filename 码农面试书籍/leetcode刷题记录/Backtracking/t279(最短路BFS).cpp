#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n;
int numSquares(int n){
	queue<pair<int,int> > Q;
	typedef pair<int,int> P;
	bool* visit=new bool[n+5];
	for(int i=0;i<=n;i++){
		visit[i]=false;
	}
	P q;
	Q.push(P (n,0));
	int num=INT_MAX;
	while(!Q.empty()){
		q=Q.front();
		visit[q.first]=true;
		Q.pop();
		int m=sqrt(q.first);
		q.second++;
		for(int i=1;i<=m;i++){
			if(q.first-i*i==0){
				if(q.second<num) num=q.second;
			}
			else if(!visit[q.first-i*i]&&q.second<num) Q.push(P (q.first-i*i,q.second));
		}
	}
	return num;
}

int main(){
	while(~scanf("%d",&n)){
		printf("%d\n",numSquares(n));	
	}
	return 0;
} 
