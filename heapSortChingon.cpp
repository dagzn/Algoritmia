#include <iostream>
using namespace std;

void cambiar(int A[], int a, int b){
	int aux;
	aux = A[a];
	A[a]=A[b];
	A[b]=aux;
}

void heapify(int A[], int n, int i){
	int left,right,largest;
	left = 2*i + 1;
	right = 2*i + 2;
	largest = i;
	if(left < n && A[left] > A[largest])
		largest = left;
	if (right < n && A[right] > A[largest] )
		largest = right;
	if(largest != i){
		cambiar(A,i,largest);
		heapify(A,n,largest);
	}
}

void maxHeap(int A[], int n){
	for (int i = (n/2)-1; i >= 0; i--)
	{
		heapify(A,n,i);
	}
}

void heapSort(int A[],int n){
	maxHeap(A,n);
	for (int i = n-1; i >= 0 ; i--)
	{
		cambiar(A,0,i);
		heapify(A,i,0);
	}
}


int main(){
	int A[5];
	int n;

	for (int i = 0; i < 5; ++i)
	{
		cin >> A[i];
	}

	n = sizeof(A)/sizeof(*A);
	heapSort(A,n);

	for (int i = 0; i < 5; ++i)
	{
		cout << A[i] << "\n";
	}
}