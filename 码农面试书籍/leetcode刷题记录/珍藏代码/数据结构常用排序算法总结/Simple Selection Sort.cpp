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
        for (int i = 1; i < n ; i++){
            int min = i;
            for (int j = i + 1; j <= n; j++){
                if (a[j] < a[min]) min = j;
            }
            if(min!=i) swap(a[i], a[min]);
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}