#include <bits/stdc++.h>
using namespace std;

vector<int> volume;
vector<vector<int>> table;
int n,a,b;

int concert(int pos,int sum){
	if(sum < 0 || sum > b){
		return -1;
	}
	if(pos == n){
		table[pos][sum]=sum;
		return sum;
	}
	if(table[pos][sum] != -1000)
		return table[pos][sum];

	return table[pos][sum] = max(concert(pos+1,sum-volume[pos]),concert(pos+1,sum+volume[pos]));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int v;
	cin >> n;
	volume.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		volume[i]=v;
	}
	cin >> a >> b;
	vector<int> aux(b+10,-1000);
	table.resize(60,aux);
	cout << concert(0,a) << endl;
	return 0;
}