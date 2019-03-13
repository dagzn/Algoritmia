#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
#define EPS 1e-9
/*
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
*/
void combine(int a, int b, vector<double> & ans,vector<double> &A){
	ans.push_back(0);
	for(int i = a; i <= b; i++){
		int size = ans.size();
		for(int j = 0; j < size; j++){
			ans.push_back(ans[j] + A[i]);
		}
	}
	sort(ans.begin(), ans.end());
}

bool compare(double a, double b){
	if(abs(a - b) < EPS)
		return false;
	return a < b;
}

lli dejaVu(lli n,lli k, string s, vector<double> &numbers){
	vector<double> left;
	vector<double> right;
	/*
	fillArray(0,n/2,numbers,left);
	fillArray(n/2,n-(n/2),numbers,right);
	*/
	combine(0, (n - 1) / 2, left,numbers);
	combine((n - 1) / 2 + 1, n - 1, right,numbers);
	lli total=0;
	
	double logK=log10(k);

    for (int x = 0; x <= s.size()-1; ++x){
    	lli sub=0;
    	for (int i = 0; i < left.size(); ++i){
    		int p =(lower_bound(right.begin(), right.end(), logK-x-left[i],compare) - right.begin());
    		if(p >=right.size())
    			continue;
    		if(i == 0 && p == 0)
    			p++;
    		sub+=(right.size()-p);
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
