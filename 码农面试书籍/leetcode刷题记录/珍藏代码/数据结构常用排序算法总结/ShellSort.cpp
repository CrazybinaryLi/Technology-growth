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
	//对数组a做一趟希尔排序。本算法是和一趟直接插入排序相比，作了以下修改：
	//1.前后记录位置的增量是dk，而不是1；
	//a[0]只是暂存单元，不是哨兵。当j<=0时，插入位置已找到
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
	//按照增量n/2,n/4,...,1的顺序作希尔排序
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

//希尔排序是不稳定的算法，平均时间复杂度O(n^1.3),最好O（n），最坏O（n^2）。