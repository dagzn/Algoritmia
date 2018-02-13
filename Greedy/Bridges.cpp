#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
void bridges(priority_queue<int> puntoA,pii primer){
	priority_queue<int> puntoB;
	puntoA.push(primer.first);
	puntoB.push(-(primer.second));
	cout << primer.first<< " " <<primer.second << "\n";
	cout << primer.first << endl;	

	while(true){

		int aux = 0;
		cout << puntoA.top();

		puntoB.push(-puntoA.top());
		puntoA.pop();
		if(!puntoA.empty()){
			puntoB.push(-puntoA.top());
			cout << " "<< puntoA.top() << "\n";
			puntoA.pop();
		}
		if(puntoA.empty())
			break;
		puntoA.push(-puntoB.top());
		cout << -puntoB.top() << endl;
		puntoB.pop();
		
	}
	
}

int main(){
	int T,n,p;
	cin >> T;
	for (int i = 0; i < T; ++i){
		vector<int> aux;
		priority_queue<int> puntoA;
		cin >> n;
		for (int j = 0; j < n; ++j){
			cin >> p;
			aux.push_back(p);
		}	
		sort(aux.begin(),aux.end());
		pii primer = pii(aux[0],aux[1]);
		for (int i = 2; i < aux.size(); ++i){
			puntoA.push(aux[i]);
		}
		bridges(puntoA,primer);
	}
	return 0;
}