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
				a[0] = a[i];                      //��Ҫ��������ݴ浽a[0]              
				int low = 1, high = i - 1;
				while (low <= high){
					int mid = (low + high) / 2;
					if (a[mid] > a[0]) high = mid - 1;
					else low = mid + 1;
				}
				for (int j = i - 1; j >= high + 1; j--) a[j + 1] = a[j];
				a[high + 1] = a[0];              //high+1Ϊ�����λ��
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

//�۰����������˹ؼ��ּ�ıȽϴ���������¼���ƶ��������䡣��ˣ��۰���������ʱ�临�Ӷ���ΪO��n^2�����۰����Ҳ���ȶ����㷨��