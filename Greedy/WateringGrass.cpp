#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<float,float> pff;


bool checkRange(pff r, pff o){
	if(r.first <= o.first){
		if(r.second <= o.first)
			return false;
		else
			return true;
	}
	return false;
}

vector<pff> minCoverage(vector<pff> ranges, pff origin){
	vector<pff> res;
	while(true){
		int reach=origin.first;
		pff max = pff(0,0);
		for (int i = 0; i < ranges.size(); ++i){
			if(checkRange(ranges[i],origin)){
				if(ranges[i].second > reach)
					max = ranges[i];
			}
		}
		if(max.first == 0 && max.second == 0)
			break;
		res.push_back(max);
		if(max.second >= origin.second)
			break;
		else
			origin.first = max.second;
	}
	return res;
}

int main(){
	float n,l,w;
	while(cin >> n >> l >> w){
		float p,r;
		vector<pff> pos;
		for (int i = 0; i < n; ++i){
			cin >> p >> r;
			if(r >= w/2){
				float root = pow(r,2) - pow((w/2),2);
				//cout << "La raiz es: " << root << endl;
				float a = p - sqrt(root);
				float b = p + sqrt(root);
				pos.push_back(pff(a,b));
				//cout <<"Rango: " << a << " " << b << "\n";
			}
		}
		vector<pff> res = minCoverage(pos,pff(0,l));
		if(res.size())
			cout << res.size() << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}