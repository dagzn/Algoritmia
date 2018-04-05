#include <bits/stdc++.h>
using namespace std;
vector<int> BIT;
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

int getSum(int index)
{
    int sum = 0;
    for (; index > 0; index -= index & (-index))
         sum += BIT[index];
    return sum;
}
 
void updateBIT(int n, int index, int val)
{
    for(; index <= n; index += index & (-index))
        BIT[index] += val;
}

// Converts an array to an array with values from 1 to n
// and relative order of smaller and greater elements remains
// same.  For example, {7, -90, 100, 1} is converted to
// {3, 1, 4 ,2 }
void convert(vector<int> &arr,vector<int> &temp)
{
    // Create a copy of arrp[] in temp and sort the temp array
    // in increasing order
    //int temp[n];
    int max=0;
    sort(temp.begin(), temp.end());
 
    // Traverse all array elements
    for (int i=0; i < arr.size(); i++)
    {
        // lower_bound() Returns pointer to the first element
        // greater than or equal to arr[i]
        arr[i] = lower_bound(temp.begin(), temp.end() ,arr[i]) - temp.begin() + 1;
    }
}

void queryResults(vector<int> &a, int n, vector<queer> &q, int m)
{
    
    block = ceil(sqrt(n));
    vector<int> resultados(m);
    int tamanio=0;
    int res = 0;
    int num = 0;
    sort(q.begin(), q.end(), compare);
    
    
    
    int l = q[0]->L;
    int r = q[0]->R;
    //cout << "Hacemos a " << l << " " << r << endl;
    for (int i = r; i >= l; --i){
        int num = a[i];
        res += getSum(num-1);
        updateBIT(n, num, 1);
    }
    int aux=0;
    resultados[q[0]->id] = res; 
    //cout << "El resultado es " << res << endl;
    int currL = l, currR = r;
    for (int i=1; i<m; i++)
    {
    	//res = 0;
        int L = q[i]->L, R = q[i]->R;
        //cout << "Hacemos a " << L << " " << R << endl;
        //QUITAR IZQUIERDA
        while (currL < L)
        {
            num = a[currL];
            //cout << "Quitamos por la izq a " << num <<endl;
            res -= getSum(num-1);
            //cout << "Quitamos a res los numeros menores: " <<getSum(num-1) << endl;
            updateBIT(n, num, -1);
            currL++;
        }
        //SUMAR IZQUIERDA
        while (currL > L)
        {
            num = a[currL-1];
            //cout << "Sumamos por la izq a " << num <<endl;
            res += getSum(num-1);
            //cout << "Sumamos a res los numeros menores: " << getSum(num-1) << endl;
            updateBIT(n, num, 1);
            currL--;
        }
        //SUMAR DERECHA
        while (currR < R)
        {
            num = a[currR+1];
            //cout << "Sumamos por la der a " << num <<endl;
            tamanio = currR+1-currL;
            //cout << "El tamanio es: " << tamanio << endl;
            res+= tamanio - getSum(num-1);
            //cout << "Sumamos a res los numeros mayores: " << getSum(num-1) << endl;
            updateBIT(n, num, 1);
            currR++;
        }
 		//QUITAR DERECHA
        while (currR > R)
        {
            num = a[currR];
            //cout << "Quitamos por la der a " << num <<endl;
            tamanio = currR+1-currL;
            //cout << "El tamanio es: " << tamanio << endl;
            res-= tamanio - getSum(num-1);
            //cout << "Restamos a res los numeros mayores: " << getSum(num-1) << endl;
            updateBIT(n, num, -1);
            currR--;
        }
        resultados[q[i]->id]=res;
        //cout << "El resultado es " << res << endl; 
    }
    //cout << "Rompe 1\n";
    for (int i = 0; i < resultados.size(); ++i)
    {
        cout << resultados[i] << "\n";
    }
    //cout << "Rompe 2\n";
}

int main()
{
    int n,m,x,y,max=0;
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    vector<int> a(n);
   	vector<int> temp(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[i]=x;
        temp[i]=x;
    }
    convert(a,temp);
    
    BIT.resize(n,0);
    //cin >> m;
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
    queryResults(a, n, q, m);
    /*
    for (int i = 0; i < a.size(); ++i)
    {
    	cout << a[i] << " ";
    }*/
    return 0;
}
