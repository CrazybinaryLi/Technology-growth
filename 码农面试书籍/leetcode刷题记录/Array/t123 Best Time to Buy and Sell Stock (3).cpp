#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> prices={1,2,4,2,5,7,2,4,9,0};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int buy1=INT_MIN;
		int buy2=INT_MIN;
		int sell1=0;
		int sell2=0;
		for(int i=0;i<prices.size();i++){
			buy1=max(buy1,-prices[i]);
			sell1=max(sell1,buy1+prices[i]);
			buy2=max(buy2,sell1-prices[i]);
			sell2=max(sell2,buy2+prices[i]);
		}
		return sell2;
    }
};

int main(){
	Solution S;
	cout<<S.maxProfit(prices)<<endl;
	return 0;
}
