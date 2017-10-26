#include <bits/stdc++.h>
using namespace std;
struct Pareja
{
	char first;
	int second;
};
int main(){
	string str;
	vector<Pareja> par;
	Pareja aux;
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		aux.first = str[i];
		aux.second = i;
		par.push_back(aux);
	}
	std::sort(par.begin(),par.end(), [](Pareja a, Pareja b){
		return b.first > a.first;
	});
	
	for (int i = 0; i < par.size(); ++i)
	{
		cout << par[i].first << " " << par[i].second << endl;
	}
	
	int to=0;
	char b;
	while(true){
		to = par[to].second;
		b = par[to].first;
		if(par[to].first == '$')
			break;
		cout << b; 
	}
	return 0;
}