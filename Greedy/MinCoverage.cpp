#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


vector<pii> minCoverage(priority_queue<pii> ranges, pii origin){
	vector<pii> res;
	while(true){
		int reach=origin.first;
		pii max = pii(0,0);
		for (int i = 0; i < ranges.size(); ++i){
			pii aux = ranges.top();
			if(-aux.first <= origin.first){
				if(aux.second > origin.first){
					if(aux.second > reach)
						max = pii(-aux.first,aux.second);
				}
				ranges.pop();
			}
			else
				break;
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
	int T,M;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int a,b;
		vector<pii> ranges;
		priority_queue<pii> pq;
		cin >> M;
		while(true){
			cin >> a >> b;
			if(!a && !b)
				break;
			//ranges.push_back(pii(a,b));
			pq.push(pii(-a,b));
		}
		vector<pii> res = minCoverage(pq,pii(0,M));
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); ++i){
			cout << res[i].first << " " << res[i].second << "\n"; 
		}
	}
	return 0;
}