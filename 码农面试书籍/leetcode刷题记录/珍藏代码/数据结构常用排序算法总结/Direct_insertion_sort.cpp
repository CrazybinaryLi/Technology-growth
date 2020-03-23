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

int main(){
	int n;
	int a[101];
	while (scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 2; i <= n; i++){                   //假设第一个数有序，依次从第二个数到第n个数与前一个数比较，总共进行n-1趟排序
			if (a[i] < a[i - 1]){
				a[0] = a[i];                            //"<"需将a[i]设置为哨兵，防止越界的小技巧
				int j;
				for (j = i - 1; a[j] > a[0]; j--){      //从i前一个位置开始后移
 					a[j + 1] = a[j];
				}
				a[j + 1] = a[0];
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

//直接插入排序是稳定的算法，时间复杂度为O（n^2）