#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Lista;

int binarySearch(int ini, int fin, Lista arr,int buscar){
	int pos = (fin - ini)/2;
	if(ini == fin)
		cout << "Error";
		exit(1);
	if(buscar == arr[pos])
		return pos;
	if(buscar < arr[pos])
		binarySearch(ini,pos,arr,buscar);
	if(buscar > arr[pos])
		binarySearch(pos+1,fin,arr,buscar);
}	

int main(){
	int n,buscar;
	cout << "N";
	cin >> n;
	Lista arr = Lista(n);
	cout << "Numeros";
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	cout << "Numero a buscar: \n";
	cin >> buscar;

	cout<< binarySearch(0,n-1,arr,buscar);
}