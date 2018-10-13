#include <bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin >> s1 >> s2;
	int n=s2.size();
	int m = s1.size();

	int L[m+1][n+1]; 
   	int i, j; 
   	for (i=0; i<=m; i++){ 
     	for (j=0; j<=n; j++) { 
       		if (i == 0 || j == 0) 
         		L[i][j] = 0; 
       		else if (s1[i-1] == s2[j-1]) 
         		L[i][j] = L[i-1][j-1] + 1; 
       		else
         		L[i][j] = max(L[i-1][j], L[i][j-1]); 
     	}
   	} 
	cout << L[m][n];
	return 0;
}