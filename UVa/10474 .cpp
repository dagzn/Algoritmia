#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int binaria(vector<int> &num,int search){
	int left=0,right=num.size()-1,middle;
	int resultado=-1;
	for(int i =0; i < 15; i++){
		middle = (left+right)/2;
		if(num[middle] == search){
			resultado = middle;
			right = middle-1;
		}
		else{
			if(num[middle] > search)
				right = middle-1;
			else
				left = middle+1;
		}
	}
	return resultado;
}
int main(){
	int n,q,cont=0,query;
	while(true){
		cin >> n >>q;
		if(!n && !q)
			break;
		vector<int> num(n);
		cont++;
		for (int i = 0; i < n; ++i){
			cin >> num[i];
		}
		sort(num.begin(), num.end());
		cout << "CASE# " << cont << ":"<< endl;
		for (int i = 0; i < q; ++i){
			cin >> query;
			int res=binaria(num,query);
			if(res >=0)
				cout << query << " found at " << res+1 << endl;
			else
				cout << query << " not found\n";
		}
	}
	return 0;
}
