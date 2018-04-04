
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
#define EPS 1e-9
void fillArray(lli ini, int n ,vector<double> &numbers, vector<double> &v){
	for (int i=0; i<(1<<n); i++)
    {
        lli s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += numbers[j+ini];
        v[i] = s;
    }
    sort(v.begin(), v.end());
}

bool compare(double a, double b){
	if(abs(a - b) < EPS)
		return false;
	return a < b;
}

lli dejaVu(lli n,lli k, string p, vector<double> &numbers){
	vector<double> left(1<<(n/2));
	vector<double> right(1<<(n-(n/2)));
	
	fillArray(0,n/2,numbers,left);
	fillArray(n/2,n-(n/2),numbers,right);
	
	lli total=0;
	
	double logK=log10(k);

    for (int x = 0; x <= p.size()-1; ++x){
    	lli sub=0;
    	for (int i = 0; i < left.size(); ++i){
    		int p = right.size() - (lower_bound(right.begin(), right.end(), logK-x-left[i],compare) - right.begin());
    		if(p == 0)
    			continue;
    		if(i == 0 && p == right.size())
    			p-=1;
    		sub+=p;
    	}
    	
    	total+=sub;
    	if(x == 0)
    		total+=sub;
    }
	return total;
}
int main(){
	lli n,k;
	string p;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lli aux;
	cin >> n >> k >> p;
	vector<double> numbers(n);
	for (lli i = 0; i < n; ++i){
		cin >> aux;
		numbers[i]=log10(aux);
	}
	cout << dejaVu(n,k,p,numbers);
	return 0;
}
