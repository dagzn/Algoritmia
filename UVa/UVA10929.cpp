#include <bits/stdc++.h>
using namespace std;
//#define __USE_MINGW_ANSI_STDIO 0
//typedef __int128 Intsote;

int divCriteria11(string num){
	int res=0;
	for (int i = 0; i < num.length(); ++i)
	{
		int aux = num[i] - '0';
		if(i == 0 || i % 2 == 0)
			res += aux;
		else
			res-=aux;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	string str;
	int check;

	while(true){
		cin  >> str;
		if(str[0] == '0')
			break;
		check=divCriteria11(str);
		if(check == 0 || check % 11 == 0){
			cout << str << " is a multiple of 11.\n";
		}
		else{
			cout << str << " is not a multiple of 11.\n";
		}
		check = 0;
	}
	return 0;
}
