#include <bits/stdc++.h>

using namespace std;
vector<int> primos;
pair<vector<int>, vector<int> > mySieve(int N) {
    int n = N + 1;
    vector<int> dic(n);
    vector<int> primes;
    if (N == 2)
        primes = {2};
    if (N > 2)
        primes = {2, 3};
    dic[0] = -1;
    dic[1] = 1;
    for (int i = 4; i < n; i += 2)
        dic[i] = 2;
    for (int i = 9; i < n; i += 3)
        dic[i] = 3;
    int i = 5, w = 2, k = i * i;
    while (k < n) {
        if (dic[i] == 0) {
            primes.push_back(i);
            // skip multiples of 2
            int jump = 2 * i;
            for (long long int j = k; j < n; j += jump)
                dic[j] = i;
        }
        i += w;
        w = 6 - w;
        k = i * i;
    }
    // if you need primes bigger than the root of N
    /*
    while (i < n) {
        if (dic[i] == 0)
            primes.push_back(i);
        i += w;
        w = 6 - w;
    }
    */
    return {dic, primes};
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
    vector<pair<int,int>> factors = primeFactorization(b);
    int cont=0,aux,total=0;
    for (int i = 0; i < factors.size(); ++i)
    {
        for (int j = 1; true ; ++j)
        {
            aux = pow(factors[i].first,j)
            //aux = n/pow(factors[i].first,j)+0.5;
            if(aux > n )
                break;
            cont += n/aux + 0.5;
        }
        if(factors[i].second != 1)
            cont= floor(cont / factors[i].second);
        total +=cont;
    }
}

int forBase10(int n){
    int res=0;
    for (int i = 1; true ; ++i)
    {
        if ((n/(pow(5,i))+0.5) == 0)
            break;
        res+= (n/(pow(5,i)) + 0.5);
    }
    return res;
}

int main(){
    int N,B;
    primos = mySieve(1000).second;
    while(cin >> N >> B){
        if(B == 10){
            cout << forBase10(N) << endl;
        }
        else{

        }
    }
    
    return 0;
}