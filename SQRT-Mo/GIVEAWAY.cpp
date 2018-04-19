#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<int,int> BIT;
typedef pair<int,int> pii;
struct block
{
    int l,r;
    BIT ft;
};
//unordered_map<int,int> BIT;
vector<block> bloques;
int getSum(int index,unordered_map<int,int> &BIT)
{
    int sum = 0;
    for (; index > 0; index -= index & (-index))
         sum += BIT[index];
    return sum;
}
 
void updateBIT(int n, int index, int val,unordered_map<int,int> &BIT)
{
    for(; index <= n; index += index & (-index))
        BIT[index] += val;
}




int query(vector<int> &numbers,int l,int r, int val,int b)
{
    int resultado=0;
    while(true){
        int idx_l=(int)l/b;
        int idx_r=(int)r/b;
        if(l == bloques[idx_l-1].l){
            if((idx_l != idx_r) || bloques[idx_r].r == r){
                resultado+=getSum(val,bloques[idx_l-1].ft);
                l+=b;
            }
            else{
                for (int i = l; i <=r; ++i){
                    if(numbers[i] < val){
                        resultado++;
                    }
                }
            }
        }
        else{
            for (int i = l; i <=r; ++i){
                int idx_i = (int) i/b;
                if(idx_i != idx_l){
                    l=i;
                    break;
                }
                if(numbers[i] < val){
                        resultado++;
                }
            }
        }
        if(l == r){
            if(numbers[l] < val)
                resultado++;
            break;
        }
    }
    return resultado;
}
/*
void update(vector<int> &numbers,int i,int val){

}
*/
void fillArray(vector<int> &numbers,vector<pair<int,pii>> &indices){
    
    for (int i=0; i< indices.size();i++){
        BIT fenwick;
        pair<int,pii> p = indices[i];
        for (int j=p.second.first; j<=p.second.second; j++){
            cout << "Metemos a " << numbers[j] << " al BIT numero " << i+1 << endl;
            updateBIT(p.first, numbers[j], 1,fenwick);
        }
        block s;
        s.l=p.second.first;
        s.r=p.second.second;
        s.ft=fenwick;
        bloques[i]=s;
    }
}


int main()
{
    int n,m,t,x,y,val;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    vector<int> num(n);
    int b = floor(sqrt(n));
    bloques.resize(ceil(sqrt(n)));
    vector<pair<int,pii>> indices(ceil(sqrt(n)));
    
    int cont=0,pos=0, max =0;
    pair<int,pii> p;
    for (int i = 0; i <= n; ++i){
        if(cont == b){
            p.second.second=i-1;
            p.first=max;
            indices[pos]=p;
            pos++;
            cont=0;
            max=0;
        }
        if(cont == 0)
            p.second.first=i;
        if(i==n){
            p.second.second=i-1;
            p.first=max;
            indices[pos]=p;
            break;
        }
        cin >> x;
        num[i]=x;
        if(x > max)
            max = x;
        cont++;
    }
    fillArray(num,indices);
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> val;
        cout <<query(num,x-1,y-1,val,b) << endl;
    }
    /*
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> t;
        if(t == 0){
            cin >> x >> y >> val;
            query(num,x,y,val)
        }
        else{
            cin >> x >> val;
            update(num,x,val);
        }
    }
    */
    return 0;
}