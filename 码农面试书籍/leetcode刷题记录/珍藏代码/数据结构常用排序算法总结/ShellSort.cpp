#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int a[101],*aa;
void ShellInsert(int *aa, int dk, int n){
	//������a��һ��ϣ�����򡣱��㷨�Ǻ�һ��ֱ�Ӳ���������ȣ����������޸ģ�
	//1.ǰ���¼λ�õ�������dk��������1��
	//a[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ�����ҵ�
	for (int i = dk + 1; i <= n; i ++){
		if (aa[i] < aa[i - dk]){
			aa[0] = aa[i];
			int j;
			for (j = i - dk; j > 0 && aa[j] > aa[0]; j-=dk){
				aa[j + dk] = aa[j];
			}
			aa[j + dk] = aa[0];
		}
	}
}

void ShellSort(int *aa,int n){
	//��������n/2,n/4,...,1��˳����ϣ������
	for (int dk = n/2; dk >= 1; dk /= 2){
		ShellInsert(aa, dk, n);
	}
}

int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		aa = a;
		ShellSort(aa, n);
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

//ϣ�������ǲ��ȶ����㷨��ƽ��ʱ�临�Ӷ�O(n^1.3),���O��n�����O��n^2����