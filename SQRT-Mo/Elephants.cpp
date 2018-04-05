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

void elefantes(vector<int> &a, int n, vector<queer> &q, int m)
{
    block = (int)sqrt(n);
    //vector de resultados
    vector<int> resultados(m);
    sort(q.begin(), q.end(), compare);
    //tabla para guardar los numeros y sus repeticiones
    unordered_map<int,int> numbers;
    int res=0;

    int l = q[0]->L;
    int r = q[0]->R;
    //Solo el primero se hace individual
    for (int i = l; i <= r; ++i){
        int num = a[i];
        if(numbers[num] == num)
        	res--; 	
        numbers[num]++;
        if(numbers[num] == num)
            res++;
    }

    int num = 0;
    resultados[q[0]->id] = res; 
    int currL = l, currR = r;

    for (int i=1; i<m; i++)
    {
        int L = q[i]->L, R = q[i]->R;
        while (currL < L)
        {
            num = a[currL];
            if(numbers[num] == num)
            	res--;

            numbers[num]--;

            if(numbers[num] == num)
                res++;
            currL++;
        }
 
        while (currL > L)
        {
            num = a[currL-1];
            if(numbers[num] == num){
                res--;
            }
            numbers[num]++;
            if(numbers[num] == num){
                res ++;
            }
            currL--;
        }
        while (currR < R)
        {
            num = a[currR+1];
            if(numbers[num] == num){
                res--;
            }
            numbers[num]++;   
            if(numbers[num] == num){
                res ++;
            }
            currR++;
        }
 

        while (currR > R)
        {
            num = a[currR];
            if(numbers[num] == num)
            	res--;

            numbers[num]--;

            if(numbers[num] == num)
                res++;
            currR--;
        }
    	//guarda el resultado en la posicion indicada con respecto al orden en que se dio el query
        resultados[q[i]->id]= res; 
    }
    for (int i = 0; i < resultados.size(); ++i)
    {
        cout << resultados[i] << endl;
    }
}

int main()
{
    int n,m,x,y;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[i]=x;
    }
    
    vector<queer> q(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        queer aux = new Query();
        aux->L = x-1;
        aux->R = y-1;
        aux->id=i;
        q[i]=aux;
    }
    elefantes(a, n, q, m);
    return 0;
}
