#include <bits/stdc++.h>
using namespace std;
int n;
int LIS(vector<int> &num){
	vector<int> memo(n,1);
	for (int i = n-1; i >= 0;--i){
		for (int j = i; j < n; ++j){
			if(num[i] < num[j])
				memo[i] = max(memo[i],memo[j]+1);
		}
	}
	int res=0;
	for (int i = 0; i < n; ++i){
		//cout << memo[i] << " ";
		res=max(res,memo[i]);
	}
	return res;
}
int main(){
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i){
		cin >> num[i];
	}
	cout << LIS(num);
	return 0;
}