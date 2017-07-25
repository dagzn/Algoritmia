#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef vector<int> Lista;


void MergeSort(int ini,int fin,Lista &nums){
	Lista aux;
	
	if(ini == fin) 
		return;
	
	int mitad = (ini+fin)/2;
	
	MergeSort(ini,mitad,nums);
	MergeSort(mitad+1,fin,nums);
	
	int izq = ini, der = mitad+1;
	
	while(izq <= mitad && der <= fin){
		if(nums[izq] < nums[der]) 
			aux.push_back(nums[izq++]);
		else 
			aux.push_back(nums[der++]);	
	}
	while(izq <= mitad) 
		aux.push_back(nums[izq++]);
	while(der <= fin) 
		aux.push_back(nums[der++]);
	for(int i = 0 ; i < aux.size(); i++)
		nums[ini+i] = aux[i];		
}


int main(){

	int N;

	optimizar_io

	cin >> N ;

	Lista num = Lista(N);

	for(int i =0 ; i < N ; i++)
		cin>> num[i];

	MergeSort(0,N-1,num);

	for(int i = 0 ; i < N ; i++)
		cout << num[i] << ' ' ;
	cout << '\n';
	cout << 5/2;
	return 0;
}