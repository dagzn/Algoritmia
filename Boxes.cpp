#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	int X,R,N,L,count = 0,h = 0;
	cin >> X;
	for (int i = 0; i < X; ++i)
	{
		cin >> R >> N >> L;
		 if(N == 4){
		 	if((L/sqrt(2)) < R){
		 		count++;
		 	}
		 }
		 else{
		 	if(N == 3){
		 		h = (sqrt(3)/2)*(L);
		 		if((2*h)/3 < R){
		 			count++;
		 		}
		 	}
		 }
	}

	cout << count;
	return 1;
}