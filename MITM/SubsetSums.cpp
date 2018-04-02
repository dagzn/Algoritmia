#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void fillArray(ll ini, int n ,vector<ll> &numbers, vector<ll> &v){
	for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += numbers[j+ini];
        v[i] = s;
    }
}

ll subsetSum(int n,ll a, ll b, vector<ll> &numbers){
	vector<ll> left(1<<(n/2));
	vector<ll> right(1<<(n-(n/2)));
	
	fillArray(0,n/2,numbers,left);
	fillArray(n/2,n-(n/2),numbers,right);
	
	ll contador=0;
	sort(right.begin(), right.end());
	
	for (int i=0; i<left.size(); i++)      
        	contador += upper_bound(right.begin(), right.end(),b-left[i]) - lower_bound(right.begin(), right.end(), a-left[i]);
	
	return contador;
}
int main(){
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a,b,aux;
	cin >> n >> a >> b;
	vector<ll> numbers(n);
	for (ll i = 0; i < n; ++i)
	{
		cin >> aux;
		numbers[i]=aux;
	}
	cout << subsetSum(n,a,b,numbers) << "\n";
	return 0;
}
