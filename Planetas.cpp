#include <iostream>
#include <vector>
using namespace std;

double sacarSuma(vector <int> planetas,float pos){
	double total=0.0;
	//cout << pos << endl;
	for (int i = 0; i < planetas.size(); ++i)
	{
		total = total + (1/(planetas[i]-pos));
	}
	//cout <<"Total es:" << total << endl;
	return total;
}

void binarySearch(vector<int> arr){
	float middle, left =arr[0],right =arr[arr.size()-1] ;
	double suma;
	while(left <= right){
		middle = (left + right)/2;
		suma = sacarSuma(arr,middle);
		if(suma < 0.0001 && suma > -0.0001){
			cout << "El resultado es:"<< middle << endl;
			right = middle+1;
		}
		if(suma < 0)
			right = middle-0.0001;
		else
			left = middle + 0.0001;
	}
	return ;
}


int main(){
	int N,a;
	vector <int> planetas;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		planetas.push_back(a);
	}

	binarySearch(planetas);
	//cout << "El resultado es:"<< binarySearch(planetas);

	return 1;
}