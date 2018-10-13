#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<int> v(n),b(m);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	for (int i = 0; i < m; ++i){
		cin >> b[i];
	}
	int j =0,i=0,res=0;
	while(i < n && j < m){
		if(b[j] >= v[i]){
			res++,j++,i++;
		}
		else{
			i++;
		}
	}
	cout << res;
	return 0;
}