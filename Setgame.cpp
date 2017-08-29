#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


char regresa(string v1, string v2,string ini,int a){
	if(v1[a] == v2[a]){
		return v1[a];
	}
	for (int i = 0; i < 3; ++i)
	{
		if((v1[a] != ini[i] && v2[a] != ini[i])){
			return ini[i];
		}
	}
	return 'T';
}


int main(){
	int N;
	string ini1 = "123";
	string ini2 = "ABC";
	string ini3 = "EFG";
	string ini4 = "XYZ";
	vector<string> cadenas = {"123","ABC","EFG","XYZ"};
	string v1,v2;
	string ans="";

	cin >> N;
	

	for (int i = 0; i < N; ++i)
	{
		cin >> v1 >> v2;
		for (int j = 0; j < 4; ++j)
		{
			ans+=regresa(v1,v2,cadenas[j],j);
		}
	}
	

	cout << ans << endl;

	return 1;

}
