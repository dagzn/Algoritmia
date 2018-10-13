//http://codeforces.com/problemset/problem/789/A
#include <iostream>
#include <algorithm>
#include <vector>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	int n,k,viajes=0,aux,seguir = 0; 
	vector<int> p;
	
	optimizar_io

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> aux;
		p.push_back(aux);
	}
	int a=0;
	
	while(p[n-1] != 0){
		
		for (int i = 0; i < 2; ++i){

			if(p[a] >= k){
				p[a]=p[a] - k;
				if (p[a] == 0)
				{
					a++;
				}
			}
			else{
				p[a] = 0;
				a++;
			}
		}

		viajes++;
	}

	cout << viajes;
	
	return 0;		
}
