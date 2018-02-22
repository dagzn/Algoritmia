#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pdd;
pdd calculateRange(int x, int y,int d){
	double h;
	h = x - sqrt(pow(d,2) - pow(y,2));
	return pdd(x-h,x+h);
}
int checkRadars(vector<pdd> ranges){
	int res=0;
	
	return res;
}
int main(){
	int n,d,cont=1;
	while(true){
		cin >> n >> d;
		if(!n && !d)
			break;
		int x,y;
		vector<pdd> ranges(n);
		for (int i = 0; i < n; ++i){
			cin >> x >> y;
			//pdd r = calculateRange(x,y);
			ranges.push_back(calculateRange(x,y));
		}
		cout << "Case " << cont << ": " << checkRadars(ranges) << "\n";
	}
	return 0;
}