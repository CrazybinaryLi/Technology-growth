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

void swap(int &a, int &b){
	int tmp;
	tmp = a;
    a = b;
	b = tmp;
}

int main(){
	 int n;
	int a[101];
	while (scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i < n; i++){
			//一共进行n-1躺
				for (int j = n; j >= i + 1; j--){
				if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
				
			}
			
		}
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
		
	}
	return 0;
}