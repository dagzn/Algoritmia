#include <bits/stdc++.h>
using namespace std;

int extended_euclid(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    int x1,y1;
    int d=extended_euclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int extendedgcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = extendedgcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
	int a,b;
	while(cin >> a >> b){
		int x,y;
		int res = extended_euclid(a,b,x,y);
		cout << x << " "<< y << " " << res << endl;
	}
	return 0;
}