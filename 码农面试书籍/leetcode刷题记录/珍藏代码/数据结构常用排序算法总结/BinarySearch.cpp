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

struct student{
	char num[100];
	char name[100];
	char sex[5];
	int age;
	bool operator <(const student &A) const{
		return strcmp(num, A.num)<0;
	}
}Stu[1001];

int main(){
	int N;
	while (scanf("%d", &N) != EOF){
		for (int i = 0; i < N; i++){
			cin >> Stu[i].num >> Stu[i].name >> Stu[i].sex >> Stu[i].age;
			//cout << Stu[i].num << " " << Stu[i].name << " " << Stu[i].sex << " " << Stu[i].age << endl;
		}
		sort(Stu, Stu + N);
		long long M;
		cin >> M;
		while (M--){
			char search[100];
			cin >> search;
			int low = 0, high = N - 1;
			int mid = (low+high) / 2;
			while (low <= high){
				if (strcmp(search, Stu[mid].num) == 0){
					cout << Stu[mid].num << " "<<Stu[mid].name<<" " << Stu[mid].sex<<" " << Stu[mid].age << endl;
					break;
				}
				if (strcmp(search, Stu[mid].num) > 0){
					low = mid + 1;
					mid = (low + high) / 2;
				}
				if (strcmp(search, Stu[mid].num)<0){
					high = mid - 1;
					mid = (low + high) / 2;
				}
			}
			if (low > high){
				cout <<"No Answer!"<< endl;
			}
		}
	}
	return 0;
}
