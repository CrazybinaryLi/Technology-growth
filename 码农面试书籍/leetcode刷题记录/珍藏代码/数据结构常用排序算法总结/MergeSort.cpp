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

int a[101], b[101];//b是辅助数组
void Merge(int a[], int low, int mid, int high){//表a[low...mid]和a[mid+1...high]各自有序，将它们合并成一个有序表
	int i, j, k;
	for (k = low; k <= high; k++)  b[k] = a[k];//将a所有的元素复制到b中
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++){
		if (b[i] <= b[j]) a[k] = b[i++];       //比较b的左右两段的元素，较小值复制到a中    
		else a[k] = b[j++];
	}
	while (i <= mid) a[k++] = b[i++];          //若第一个表未检测完，复制
	while (j <= high) a[k++] = b[j++];         //若第二个表未检测完，复制
}

void MergeSort(int a[], int low, int high){
	if (low < high){
		int mid = (low + high) / 2;           //从中间划分成两个子序列
		MergeSort(a, low, mid);               //对左侧子序列进行递归排序
		MergeSort(a, mid + 1, high);          //对右侧子序列进行递归排序
		Merge(a, low, mid, high);             //归并
	}
}

int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++) cin >> a[i];
		MergeSort(a, 1, n);
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}

//每一趟归并的时间复杂度为O（n），共需进行log2n趟归并，算法的时间复杂度是O（nlog2n）。