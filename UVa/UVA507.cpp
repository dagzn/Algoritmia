#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> tupla;
int s;
/*
*/
int main(){
	int t;
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	cin >> t;
	int contador=0;
	while(t--){
		int s,x;
		scanf("%d", &s);
        int tmp = 1, st = 0xffff, ed, sum = 0, ans = 0;
        for (int i = 2; i <= s; i++) {
            scanf("%d", &x);
            sum += x;
            if (sum < 0) sum = 0, tmp = i;
            if (sum >= ans) {
            	
                if (sum > ans || (sum == ans && (i - tmp > ed - st))) {
                    st = tmp;
                    ed = i;
                }
                ans = sum;
            }
        }
        if (ans > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", ++contador, st, ed);
        else
            printf("Route %d has no nice parts\n", ++contador);	
	}
	return 0;
}