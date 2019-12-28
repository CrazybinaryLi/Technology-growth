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

int a[101], b[101];//b�Ǹ�������
void Merge(int a[], int low, int mid, int high){//��a[low...mid]��a[mid+1...high]�������򣬽����Ǻϲ���һ�������
	int i, j, k;
	for (k = low; k <= high; k++)  b[k] = a[k];//��a���е�Ԫ�ظ��Ƶ�b��
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++){
		if (b[i] <= b[j]) a[k] = b[i++];       //�Ƚ�b���������ε�Ԫ�أ���Сֵ���Ƶ�a��    
		else a[k] = b[j++];
	}
	while (i <= mid) a[k++] = b[i++];          //����һ����δ����꣬����
	while (j <= high) a[k++] = b[j++];         //���ڶ�����δ����꣬����
}

void MergeSort(int a[], int low, int high){
	if (low < high){
		int mid = (low + high) / 2;           //���м仮�ֳ�����������
		MergeSort(a, low, mid);               //����������н��еݹ�����
		MergeSort(a, mid + 1, high);          //���Ҳ������н��еݹ�����
		Merge(a, low, mid, high);             //�鲢
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

//ÿһ�˹鲢��ʱ�临�Ӷ�ΪO��n�����������log2n�˹鲢���㷨��ʱ�临�Ӷ���O��nlog2n����