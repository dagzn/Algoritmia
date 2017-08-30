#include <iostream>
#include <vector>
#include <algorithm>
//#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


/*
int binarySearch(int ini, int fin, int arr[],int buscar){
	int pos = (fin - ini)/2;

	//cout << "Entre" << arr.size() << endl;

	if(ini == fin)
		cout << "Que pinche pedo" << endl;
		return 10;
	if(buscar == arr[pos])
		return pos;
	if(buscar < arr[pos])
		//cout << "mande1" <<endl;
		binarySearch(ini,pos,arr,buscar);
	if(buscar > arr[pos])
		//cout << "mande2" <<endl;
		binarySearch(pos+1,fin,arr,buscar);
	
}*/

int binarySearch(int left, int right, int arr[], int value) {
      while (left <= right) {
            int middle = (left + right) / 2;
            if (arr[middle] == value)
                  return middle;
            else if (arr[middle] > value)
                  right = middle - 1;
            else
                  left = middle + 1;
      }
      return -1;
}	

int checar(int num, int pos, int arr[]){
	while(arr[pos-1] == num){
		pos = pos-1;
	}
	return pos;
}


int main(){
	int N,Q,aux,resul;
	
	vector<int> query;
	vector<int> resultados;

	//optimizar_io

	cin >> N >> Q;
	
	int marbles[N];

	for (int i = 0; i < N; ++i)
	{
		cin >>marbles[i];
		//marbles.push_back(aux);
	}
	
	for (int j = 0; j < Q; ++j)
	{
		cin >> aux;
		query.push_back(aux);
	}

	sort(marbles,marbles+N);

	
	for (int k = 0; k < Q; ++k)
	{	
		resultados.push_back(binarySearch(0,N-1,marbles,query[k]));
	}
	
	for (int i = 0; i < Q; ++i)
	{
		if( resultados[i] > 0){
			resultados[i] = checar(marbles[resultados[i]],resultados[i],marbles);
		}
	}

	for (int i = 0; i < resultados.size(); ++i)
	{
		if(resultados[i] < 0)
			cout << "El numero no esta"<< endl;
		else
			cout <<"Resultado:" << resultados[i]<< endl;
	}
	
	return 1; 
}