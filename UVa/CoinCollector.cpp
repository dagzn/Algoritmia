#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,n;
	ios_base::sync_with_stdio(0);
	cin>> T;
	for (int m = 0; m < T; ++m)
	{
		cin >> n;
		vector<int> num(n);
		int aux;
		for (int i = 0; i < n; ++i){
			cin >> aux;
			num[i]=aux;
		}
		sort(num.begin(),num.end());
		int carry = num[0];
		int res= 2;
		for (int i = 1; i < num.size()-1; ++i){
			if(num[i] + carry < num[i+1]){
				carry += num[i];
				res++;
			}
		}
		cout << res << "\n";
	}
	return 0;
}