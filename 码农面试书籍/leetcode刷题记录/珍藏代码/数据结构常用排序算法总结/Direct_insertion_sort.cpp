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
		for (int i = 2; i <= n; i++){                   //�����һ�����������δӵڶ���������n������ǰһ�����Ƚϣ��ܹ�����n-1������
			if (a[i] < a[i - 1]){
				a[0] = a[i];                            //"<"�轫a[i]����Ϊ�ڱ�����ֹԽ���С����
				int j;
				for (j = i - 1; a[j] > a[0]; j--){      //��iǰһ��λ�ÿ�ʼ����
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

//ֱ�Ӳ����������ȶ����㷨��ʱ�临�Ӷ�ΪO��n^2��