#include <bits/stdc++.h>
using namespace std;

float sacarSuma(vector <int> planetas,float pos){
	float total=0.0;
	//cout << pos << endl;
	for (int i = 0; i < planetas.size(); ++i)
	{
		total += (1/(planetas[i]-pos));
	}
	//cout <<"Total es:" << total << endl;
	return total;
}

float binarySearch(vector<int> arr, float left,float right){
	
	float suma,middle;
	while(left <= right){
		middle = (left + right)/2;
		suma = sacarSuma(arr,middle);
		if(suma < 0.01 && suma > -0.01){
			//cout << "El resultado es:"<< middle << endl;
			//right = middle+0.001;
			return middle;
		}
		if(suma > 0)
			right = middle-0.0001;
		else
			left = middle + 0.0001;
	}
	return -1.0;
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
	
	for (int i = 0; i < (N-1); ++i)
	{
		cout << "El resultado es:"<< setprecision(3)<<fixed << binarySearch(planetas,planetas[i],planetas[i+1]) << endl;
	}
	
	//cout << "El resultado es:"<< binarySearch(planetas,planetas[i],planetas[i+1]) << endl;

	return 1;
}