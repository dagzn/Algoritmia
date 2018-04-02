#include<bits/stdc++.h>
using namespace std;
vector<int> BIT;

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

int getInvCount(vector<int> &arr, int n, int max)
{
    int resultado = 0;
    BIT.resize(max+1,0);
    // Traverse all elements from right.
    for (int i=n-1; i>=0; i--)
    {
        // Get count of elements smaller than arr[i]
        resultado += getSum(arr[i]-1);
        updateBIT(max, arr[i], 1);
    }
    return resultado;
}

int main()
{
    int n,aux,max=0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i){
        cin >> aux;
        numbers[i]=aux;
        if(aux > max)
            max = aux;
    }
    cout  << getInvCount(numbers,n,max) << endl;
    return 0;
}