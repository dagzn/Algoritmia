#include <bits/stdc++.h>
using namespace std;
//unordered_map<char,int> w;
int dfs(int pos, string s ,unordered_map<char,int> &w){
	//cout << "Entro en posicion y caracter siguiente: " << s[pos] << " " << s[pos+1] << "\n";
	//carac[s[pos]-64]++;
	if(s[pos] == s[pos+1]){
		//cout << "son iguales y regreso " << pos+2 << endl;
		w[s[pos]]++;
		return pos+2;
	}
	int nueva =pos+1;
	while(true){
		nueva = dfs(nueva,s,w);
		//cout << "la nueva es: " << nueva << endl;
		w[s[pos]]++;
		if(s[nueva] == s[pos]){
			w[s[pos]]++;
			break;
		}
	}
	//cout << "Regresamos a: " << nueva+1 << endl;
	return nueva+1;
}

int main(){
	int T;
	string s;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		unordered_map<char,int> w;
		//vector<int> carac(26,0);
		cin >> s;
		dfs(0,s,w);
		w[s[0]]--;
		cout << "Case " << i+1 << "\n";
		for (char i = 'A'; i <= 'Z'; ++i)
		{
			if(w.count(i))
				cout << i << " = " << w[i] << "\n";
		}	
	}
	return 0;
}