#include <bits/stdc++.h>
using namespace std;
int block;
struct Query
{
    int L, R,id;
};
typedef Query* queer;

bool compare(queer x, queer y)
{
    if (x->L/block != y->L/block)
        return x->L/block < y->L/block;
 
    return x->R < y->R;
}
 

void queryResults(vector<int> &a, int n, vector<queer> &q, int m)
{
    
    block = (int)(sqrt(n));
    vector<int> resultados(m);
    
    sort(q.begin(), q.end(), compare);
    

    vector<int> numbers(1000005);
    int total = 0;
    int l = q[0]->L;
    int r = q[0]->R;
    //cout << "Hacemos la apreja :" << l << " " << r << "\n";
    for (int i = l; i <= r; ++i){
        int num = a[i];
        numbers[num]++;
        if(numbers[num] == 1){
        	//cout << "Agregamos al numero: " << num << "\n";
            total++;
        }
    }
    int num = 0;
    resultados[q[0]->id] = total; 

    int currL = l, currR = r;
    for (int i=1; i<m; i++)
    {
    	//cout << "pasa\n";
        int L = q[i]->L, R = q[i]->R;
        //cout << "Mi L y R son "<< L <<" " << R << endl;
        while (currL < L)
        {
        	//cout << "entra1\n";
            num = a[currL];
            numbers[num]--;
            if(numbers[num] == 0){
            	//cout << "quitamos el por izq " << num << endl;
                total--;
            }
            currL++;
        }
        while (currL > L)
        {
        	//cout << "entra2\n";
            num = a[currL-1];
            numbers[num]++;
            if(numbers[num] == 1){
            	//cout << "metemos el por izq " << num << endl;
                total++;
            }
            currL--;
        }
        while (currR < R)
        {
        	//cout << "entra3\n";
            num = a[currR+1];  
            numbers[num]++;
            if(numbers[num] == 1){
            	//cout << "metemos el por der " << num << endl;
                total++;           
            }
            currR++;
        }
 
        while (currR > R)
        {
        	//cout << "entra4\n";
            num = a[currR];
            numbers[num]--;
            if(numbers[num] == 0){
            	//cout << "quitamos el por der"<<num << endl;
                total--;
            }
            currR--;
        }
    
        resultados[q[i]->id]=total; 
    }
    for (int i = 0; i < resultados.size(); ++i)
    {
        cout << resultados[i] << "\n";
    }
}

int main()
{
    int n,m,x,y;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[i]=x;
    }
    
    cin >> m;
    
    vector<queer> q(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        queer aux = new Query();
        aux->L = x-1;
        aux->R = y-1;
        aux->id = i;
        q[i]=aux;
    }
    queryResults(a, n, q, m);
    return 0;
}

/*
typedef pair<int,int> pii;
int main(){
	int n,q,stop;
	cin >> n;
	vector<int> a(n);
	//vector<pii> groups(q);
	vector<vector<pii>> groups(ceil(n/sqrt(n)));
	int aux;
	for (int i = 0; i < n; ++i){
		cin >> aux;
		a[i]= aux;
	}
	cin >> q;
	int aux2,grupo;
	for (int i = 0; i < q; ++i)
	{
		cin >> aux >> aux2;
		groups[ceil(aux/sqrt(n))-1].push_back(pii(aux2,aux));
	}


	for (int cont = 0; cont < groups.size(); ++cont){
		int res = 0;
		unordered_map<int,int> numbers;
		
		int l,r,currentl,currentr;

		if(groups[cont].size() == 0)
			continue;

		sort(groups[cont].begin(),groups[cont].end());

		//Solo el primero se hace individual
		l = groups[cont][0].second;
		r = groups[cont][0].first;
		//cout << "El primero es la pareja: " << l << " " << r << endl;
		for (int i = l-1; i < r; ++i){
			int num = a[i];
			if(numbers.count(num)){
				numbers[num]++;
			}
			else{
				//cout << "agregamos a " << num << endl;
				numbers[num]=1;
			}
		}

		cout << numbers.size() << endl;
		
		currentl = l-1;
		currentr = r-1;
		
		int num=0;

		for (int i = 1; i < groups[cont].size(); ++i){

			l = groups[cont][i].second-1;
			r = groups[cont][i].first-1;
			//cout << "pareja " << l+1 << " " << r+1 <<endl;
			while(true){
				if(currentl > l){
					//cout << "Movemos l a la izquierda\n";
					if(currentl == l)
						break;
					num = a[currentl--];
					//cout << "El l es: " << currentl << "  y num es: " << a[currentl] << "\n";
					if(numbers.count(num))
						numbers[num]++;
					else
						numbers[num]=1;
				}
				else{
					//cout << "Movemos l a la derecha\n";
					if(currentl == l)
						break;
					num = a[currentl];
					//cout << "El l es: " << currentl << "  y num es: " << a[currentl] << "\n";
					
					numbers[num]--;
					if(numbers[num] == 0){
						//cout << "quitamos\n";
						numbers.erase(num);
					}
					currentl++;
				}
				//cin >> stop;
			}

			while(true){
				if(currentr > r){
					//cout << "Movemos r a la izquierda\n";
					if(currentr == r)
						break;
					num = a[currentr];
					//cout << "El r es: " << currentr << "  y num es: " << a[currentr] << "\n";
					
					numbers[num]--;
					if(numbers[num] == 0){
						//cout << "quitamos\n";
						numbers.erase(num);
					}
					currentr--;
				}
				else{
					//cout << "Movemos r a la derecha\n";
					if(currentr == r)
						break;
					currentr++;
					num = a[currentr];
					//cout << "El r es: " << currentr << "  y num es: " << a[currentr] << "\n";
					
					if(numbers.count(num)){
						//cout << "ya esta\n";
						numbers[num]++;
					}
					else{
						//cout << "agregamos\n";
						numbers[num]=1;
					}
				}
				//cin >> stop;
			}
			cout << numbers.size() << endl;
		}
	}
	
	
	return 0;
}
*/