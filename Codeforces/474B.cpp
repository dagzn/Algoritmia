//http://codeforces.com/problemset/problem/474/B
#include <iostream>
#include <vector>
//#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int binarySearch(vector<int> piles,int search){
	int left=0,right=piles.size();
	//cout << "Buscar: " <<search<<endl;
	while(left <= right){
		int middle=(left+right)/2;
		//cout << "Medio: " << piles[middle] <<endl;
		//cout << "Anterior: " << piles[middle-1] << endl;
		if(search == piles[middle])
			return middle+1;
		if(middle == 0 || middle == piles.size()-1)
			return middle+1;
		if(search < piles[middle] && search >= piles[middle-1])
			return middle+1;
		if(search < piles[middle])
			right = middle;
		else
			if(search > piles[middle])
				left = middle;
	}
	return -1;
}
int main(){
	int n,m,aux,carry=0;
	ios_base::sync_with_stdio(0);
	cin >> n;
	vector<int> piles(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> aux;
		carry += aux;
		piles[i]=carry;
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> aux;
		cout << binarySearch(piles,aux);
		if(i != m-1)
			cout << "\n";
	}
	return 1;
}
