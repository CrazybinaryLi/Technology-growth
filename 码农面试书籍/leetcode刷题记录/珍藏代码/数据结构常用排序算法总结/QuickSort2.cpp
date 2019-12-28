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

int Partition(int a[], int low, int high){    //一趟排序的划分算法
	int pivot = a[low];                       //将当前表中第一个元素设为枢轴值，对表进行划分
	while (low < high){                       //循环跳出条件
		while (low < high&&a[high] >= pivot) --high;
		a[low] = a[high];                     //将比枢轴值小的元素移到左端
		while (low < high&&a[low] <= pivot) ++low;
		a[high] = a[low];                     //将比枢轴值大的元素移到右端
	}
	a[low] = pivot;                           //枢轴元素存放到最终位置
	return low;                               //返回存放枢轴的最终位置
}

void QuickSort(int a[], int low, int high){   //利用队列模拟递归，每次出队列一次，进队列两次
	queue<int> Q;                            
	int tlow, thigh,tpivotpos;
	Q.push(low); Q.push(high);                
	while (!Q.empty()){
		tlow = Q.front();
		Q.pop();
		thigh = Q.front();
		Q.pop();
		if (tlow < thigh){
			tpivotpos = Partition(a, tlow, thigh);
			Q.push(tlow);
			Q.push(tpivotpos - 1);
			Q.push(tpivotpos + 1);
			Q.push(thigh);
		}
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

//空间复杂度最坏情况是所有的元素都入栈，为O（n），平均情况是O（log2n）。最坏时间复杂度是O（n^2），平均O（nlog2n）。