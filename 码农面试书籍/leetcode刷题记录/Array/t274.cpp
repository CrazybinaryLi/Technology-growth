#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
vector<int> citations;
int n;
int partation(vector<int>& citations,int left,int right) {
	int base=citations[left];
	while(left<right) {
		while(left<right&&citations[right]>=base) right--;
		citations[left]=citations[right];
		while(left<right&&citations[left]<=base) left++;
		citations[right]=citations[left];
	}
	citations[right]=base;
	return right;
}

void QuickSort(vector<int>& citations,int begin,int end) {
	if(begin<end) {
		int par=partation(citations,begin,end);
		QuickSort(citations,begin,par-1);
		QuickSort(citations,par+1,end);
	}
}

int hIndex(vector<int>& citations) {
	//引用的定义为：大于h的数至少有h个。
	//故当前文章的引用数如果大于包括它在内的所有后面的文章数目，则引用应该取后面的文章数目；
	//否则取当前的文章引用数。 
	int len=citations.size();
	if(len==0) return 0;
	QuickSort(citations,0,len-1);
	int h=0;
	for(int i=0; i<len; i++) {
		if(citations[i]>=len-i) {
			h=min(citations[i],len-i);
			break;
		}
	}
	return h;
}

int main() {
	int temp;
	while(~scanf("%d",&n)) {
		citations.clear();
		for(int i=0; i<n; i++) {
			cin>>temp;
			citations.push_back(temp);
		}
		printf("paper's citation is %d\n",hIndex(citations));
	}
	return 0;
}
