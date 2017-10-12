#include <bits/stdc++.h>
using namespace std;
//#define __USE_MINGW_ANSI_STDIO 0
//typedef __int128 Intsote;

int divCriteria9(string num, int depth){
	int res=0;
	for (int i = 0; i < num.length(); ++i)
	{
		int aux = num[i] - '0';
		res += aux;
	}
	depth++;
	if(res > 9){
		return divCriteria9(to_string(res),depth);
	}
	else{
		if(res % 9 == 0)
			return depth;
		else
			return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	string str;
	int check;

	while(true){
		cin  >> str;
		if(str[0] == '0')
			break;
		check=divCriteria9(str,0);
		if(check){
			cout << str << " is a multiple of 9 and has 9-degree "<< check << ".\n";
		}
		else{
			cout << str << " is not a multiple of 9." << endl;
		}
		check = 0;
	}
	return 0;
}