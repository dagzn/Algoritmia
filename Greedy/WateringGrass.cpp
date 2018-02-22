#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,double> pff;

void minCoverage(priority_queue<pff> pq, pff origin){
	vector<pff> res;
	
	bool covered = false;
	while(true){
		pff max = pff(0,0);
		double reach=origin.first;
		
		while (!pq.empty()){
			pff aux = pq.top();
			
			if((-aux.first) <= origin.first){			
				if(aux.second > origin.first){
					if(aux.second > reach){
						max = pff(-aux.first,aux.second);
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
		if(res.size() != 0)
			cout << res.size() << "\n";
	}
	else
		cout << "-1\n";
	
}

int main(){
	double n,l,w;
	ios_base::sync_with_stdio(0);
	while(cin >> n >> l >> w){
		double p,r;
		//vector<pff> pos;
		priority_queue<pff> pos;
		for (int i = 0; i < n; ++i){
			cin >> p >> r;
			if((r*2) > w){
				double root;
				double a,b;
				root = (sqrt(4*pow(r,2) -(pow(w,2))))/2;
				a = p - root;
				b = p + root;
				//cout << "Rangos son: " << a << " " << b << endl;
				pos.push(pff(-a,b));
			}
			//checkSprinkler(p,r,w,pos);
		}
		minCoverage(pos,pff(0,l));
	}
	return 0;
}
