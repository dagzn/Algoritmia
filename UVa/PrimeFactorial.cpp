#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Criba de Eratostenes de 1 a n.
vector<int> Criba(int n) {
	int raiz = sqrt(n);
	vector<int> criba(n + 1);
	for (int i = 4; i <= n; i += 2)
		criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2)
		if (!criba[i])
			for (int j = i * i; j <= n; j += i)
				if (!criba[j]) criba[j] = i;
	return criba;
}

int main(){
	int N;
	cin >> N;
	vector<int> criba = Criba(N);
	vector<int> primos;
	for( int i = 0; i <= N; i++ ){
		if( criba[i] == 0 ) 
			primos.push_back( i );
	}
	
	//Debe iniciar en i=2
	vector<int> contador(primos.size()-2);
	int i = 2;
	int aux;
	for (int num = 2; num <= N; ++num)
	{
		i =2;
		aux = num;
		//cout << "k pdo" << aux << " " << num <<endl;
		while(primos[i] <= aux && i < primos.size()){
			//cout << "AUX antes: " << aux << endl;
			while(aux%primos[i] == 0 ){
				aux = aux/primos[i];
				contador[i-2]++;
				//cout << "AUX dentro: " << aux << endl;
			}
			i++;
			//cout << "El i: " << i <<endl;
		}	
		//cout << "BYE" << endl;
	}

	
	for (int i = 0; i < contador.size(); ++i)
	{
		//if(contador[i] != 0)
			cout << "Numero: " << primos[i+2] << " con " << contador[i] << " veces" << endl;
	}
	return 0;
}
