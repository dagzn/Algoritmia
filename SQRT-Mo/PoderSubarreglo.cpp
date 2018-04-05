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
    
    block = ceil(sqrt(n));
    vector<int> resultados(m);
    int res = 0;
    int num = 0;
    sort(q.begin(), q.end(), compare);
    
    unordered_map<int,int> numbers;
    
    int l = (q[0]->L)-1;
    int r = (q[0]->R)-1;
    //cout << "Hacemos a " << l << " " << r << endl;
    for (int i = l; i <= r; ++i){
        int num = a[i];
        res+= num*(2*numbers[num]+1);
        numbers[num]++;
        
    }
    resultados[q[0]->id] = res; 

    int currL = l, currR = r;
    for (int i=1; i<m; i++)
    {
    	//res = 0;
        int L = (q[i]->L)-1, R = (q[i]->R)-1;
        //cout << "Hacemos a " << L << " " << R << endl;
        while (currL < L)
        {
            num = a[currL];

            numbers[num]--;       
            //cout << "Quitamos a " << num << " y quitamos a res un " << num*(2*numbers[num]+1) << endl;
            res-= num*(2*numbers[num]+1);
            currL++;
        }
        while (currL > L)
        {
            num = a[currL-1];
            //cout << "Sumamos a " << num << " y sumamos a res un " << num*(2*numbers[num]+1) << endl;
            res+= num*(2*numbers[num]+1);
            numbers[num]++;
            
            currL--;
        }
        while (currR < R)
        {
            num = a[currR+1];
            //cout << "Sumamos a " << num << " y sumamos a res un " << num*(2*numbers[num]+1) << endl;
            res+= num*(2*numbers[num]+1);        
            numbers[num]++;
            
            currR++;
        }
 
        while (currR > R)
        {
            num = a[currR];
            
            numbers[num]--;
            res-= num*(2*numbers[num]+1);
            //cout << "Quitamos a " << num << " y quitamos a res un " << num*((2*numbers[num+1])+1) << endl;
            currR--;
        }
        
        resultados[q[i]->id]=res; 
    }
    for (int i = 0; i < resultados.size(); ++i)
    {
        //cout << resultados[i] << "\n";
        printf("%d\n", resultados[i]);
    }

}

int main()
{
    int n,m,x,y;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    vector<int> a(n);
    vector<queer> q(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[i]=x;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        queer aux = new Query();
        aux->L = x;
        aux->R = y;
        aux->id=i;
        q[i]=aux;    
    }
    queryResults(a, n, q, m);
    return 0;
}
