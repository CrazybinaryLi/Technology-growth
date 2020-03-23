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
	//���õĶ���Ϊ������h����������h����
	//�ʵ�ǰ���µ�������������ڰ��������ڵ����к����������Ŀ��������Ӧ��ȡ�����������Ŀ��
	//����ȡ��ǰ�������������� 
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
