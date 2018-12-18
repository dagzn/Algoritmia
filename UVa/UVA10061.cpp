#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector<bool> es_primo;
vector<lli> primos;

void criba(lli n){
    es_primo.resize(n + 1, true);
    es_primo[0] = es_primo[1] = false;
    es_primo[2] = true;
    primos.push_back(2);
    for(lli i = 4; i <= n; i += 2){
        es_primo[i] = false;
    }
    lli limit = sqrt(n);
    for(lli i = 3; i <= n; i += 2){
        if(es_primo[i]){
            primos.push_back(i);
            if(i <= limit){
                for(lli j = i * i; j <= n; j += 2 * i){
                    es_primo[j] = false;
                }
            }
        }
    }
}

vector<pair<int,int>> primeFactorization(int n){
    vector<pair<int,int>> factors;
    int cont=0;
    pair<int,int> p;
    for (int i = 0; i < primos.size(); ++i)
    {
        while(n%primos[i] == 0){
            n = n/primos[i];
            cont++;
        }
        if(cont > 0){
            p.first=primos[i];
            p.second=cont;
            factors.push_back(p);
        }
        cont = 0;
        if(n == 1)
            break;
    }
    return factors;
}

int trailingZeroes(int n, int b){
    if(n == 0)
        return 0;
    vector<pair<int,int>> factors = primeFactorization(b);
    int cont=0,min=3000000;
    float aux=0;
    for (int i = 0; i < factors.size(); ++i)
    {      
        for (int j = 1; true ; ++j){            
            aux = n/(pow(factors[i].first,j));
            if(aux < 1 )
                break;
            cont += floor(aux);
        }
        if(factors[i].second != 1)
            cont= floor(cont / factors[i].second);
        if(cont < min)
            min = cont;
        cont = 0;
    }
    return min;
}

int forBase10(int n){
    if(n == 0)
        return 0;
    int res=0;
    float aux=0;
    for (int i = 1; true ; ++i)
    {
        aux = (n/(pow(5,i)));
        if (aux < 1 )
            break;
        res+= aux + 0.5;
    }
    return res;
}

int kamenetsky(int n,int b){
    if(n == 0)
        return 1;
    int total;
    total = floor(abs(0.5*((log(2*3.141592653589793238462643383279502884)-2*n+log(n)*(1+2*n))/(log(b)))))+1;
    return total;
}

int main(){
    int N,B;
    criba(800);
    ios_base::sync_with_stdio(0);
    while(cin >> N >> B){
        if(N == 0 && B == N)
            cout << "0 0"<< endl;
        else{
            if(B == 10){
            cout << forBase10(N) <<" " << kamenetsky(N,B) << endl;
            }
            else{
                cout<<trailingZeroes(N,B) << " "  << kamenetsky(N,B) << endl;
            }
        }
    }
    
    return 0;
}
