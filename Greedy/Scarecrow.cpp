#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	int T,n;
	string w;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		cin >> w;
		unordered_set<int> pos;
		int res=0;
		for (int j = 0; j < n; ++j){
			if(w[j] == '.' && !pos.count(j)){
				pos.insert(j);
				pos.insert(j+1);
				pos.insert(j+2);
				res++;
			}
		}
		cout << "Case " << i+1 << ": " << res << "\n";
	}
	return 0;
}