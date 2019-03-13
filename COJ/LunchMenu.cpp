#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void fillArray(vector<lli> &a, vector<lli> &b, vector<lli> &res){
	int k =0;
	for (int i = 0; i < a.size(); ++i){
		for (int j = 0; j < b.size(); ++j){
			res[k]= a[i] + b[j];
			k++;
		}
	}
}

lli lunchmenu(lli l, vector<lli> &left, vector<lli> &right){
	sort(right.begin(), right.end());
	lli res=0;
	for (int i = 0; i < left.size(); ++i){
		int p = upper_bound(right.begin(), right.end(),l-left[i])- right.begin();
		res+= p;
	}
	return res;
}

int main(){
	lli l;
	int m,s,d,b,a;
	while(true){
		cin >> l >> s >> m >> d >> b;
		if(!l && !s && !m && !d && !b)
			break;
		vector<lli> soup(s);
		for (int i = 0; i < s; ++i)
		{
			cin >> a;
			soup[i]=a;
		}
		vector<lli> dish(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> a;
			dish[i]=a;
		}
		vector<lli> dessert(d);
		for (int i = 0; i < d; ++i)
		{
			cin >> a;
			dessert[i]=a;
		}
		vector<lli> beverage(b);
		for (int i = 0; i < b; ++i)
		{
			cin >> a;
			beverage[i]=a;
		}
		vector<lli> left(s*m);
		fillArray(soup,dish,left);
		vector<lli> right(d*b);
		fillArray(dessert,beverage,right);
		cout << lunchmenu(l,left,right) << "\n";
	}
	
	return 0;
}