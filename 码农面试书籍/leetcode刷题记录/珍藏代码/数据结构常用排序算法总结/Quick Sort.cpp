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

int Partition(int a[], int low, int high){    //һ������Ļ����㷨
	int pivot = a[low];                       //����ǰ���е�һ��Ԫ����Ϊ����ֵ���Ա���л���
	while (low < high){                       //ѭ����������
		while (low < high&&a[high] >= pivot) --high;
		a[low] = a[high];                     //��������ֵС��Ԫ���Ƶ����
		while (low < high&&a[low] <= pivot) ++low;
		a[high] = a[low];                     //��������ֵ���Ԫ���Ƶ��Ҷ�
	}
	a[low] = pivot;                           //����Ԫ�ش�ŵ�����λ��
	return low;                               //���ش�����������λ��
}

void QuickSort(int a[], int low, int high){
	if (low < high){                          //ѭ������������
		int pivotpos = Partition(a, low, high);//����
		QuickSort(a, low, pivotpos-1);         //���ζ������ӱ���еݹ�����
		QuickSort(a, pivotpos+1, high);
	}
}

int main(){
	int n;
	int a[101];
	while (scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++) cin >> a[i];
		QuickSort(a, 1, n);
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}

//�ռ临�Ӷ����������е�Ԫ�ض���ջ��ΪO��n����ƽ�������O��log2n�����ʱ�临�Ӷ���O��n^2����ƽ��O��nlog2n����