#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


void minCoverage(priority_queue<pii> pq, pii origin){
	vector<pii> res;
	//priority_queue<pii> pq;
	bool covered = false;
	while(true){
		pii max = pii(0,0);
		int reach=origin.first;
		
		while (!pq.empty()){
			pii aux = pq.top();
			//cout << -aux.first<<" " << aux.second << endl;
			if((-aux.first) <= origin.first){			
				if(aux.second > origin.first){
					if(aux.second > reach){
						max = pii(-aux.first,aux.second);
						reach = aux.second;
					}
				}
				pq.pop();
			}
			else
				break;
		}
		
		if(max.first == 0 && max.second == 0)
			break;
		res.push_back(max);
		if(max.second >= origin.second){
			covered = true;
			break;
		}
		else
			origin.first = max.second;
	}
	if(covered){
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); ++i){
			cout << res[i].first << " " << res[i].second << "\n"; 
		}
	}
	else{
		cout << "0\n";
	}
	
}

int main(){
	int T,M;
	ios_base::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int a,b;
		priority_queue<pii> ranges;
		//vector<pii> rangos;
		cin >> M;
		while(true){
			cin >> a >> b;
			if(!a && !b)
				break;
			ranges.push(pii(-a,b));
			//rangos.push_back(pii(a,b));
		}
		
		minCoverage(ranges,pii(0,M));
		if(i != T-1)
			cout << "\n";
	}
	return 0;
}
