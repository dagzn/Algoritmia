#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		if(!n)
			break;
		//vector<int> num(n);
		int x;
		int sum=0,ans=0;
		for (int i = 0; i < n; ++i){
			cin >> x;
			sum+=x;
			ans=max(ans,sum);
			if(sum < 0)
				sum=0;
		}
		if(ans > 0)
			cout << "The maximum winning streak is " << ans << ".\n";
		else
			cout << "Losing streak.\n";
	}
	return 0;
}