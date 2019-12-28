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
		for (int i = 2; i <= n; i++){
			if (a[i] < a[i - 1]){
				a[0] = a[i];                      //将要插入的数暂存到a[0]              
				int low = 1, high = i - 1;
				while (low <= high){
					int mid = (low + high) / 2;
					if (a[mid] > a[0]) high = mid - 1;
					else low = mid + 1;
				}
				for (int j = i - 1; j >= high + 1; j--) a[j + 1] = a[j];
				a[high + 1] = a[0];              //high+1为插入的位置
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

//折半插入仅减少了关键字间的比较次数，而记录的移动次数不变。因此，折半插入排序的时间复杂度仍为O（n^2）。折半插入也是稳定的算法。