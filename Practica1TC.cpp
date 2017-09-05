#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> indexCreation(vector<string> match){
	int m = match.size();
	vector<int> arr(m);
	arr[0] = 0;
	int i =1,j=0;
	while(i < m){
		if(match[i] == match[j]){
			j++;
			arr[i] = j;
			i++;
		}

		if(match[i] != match[j] && j == 0){
			arr[i] = j;
			i++;
		}

		if(match[i] != match[j] && j != 0){
			j = arr[j-1];
		}
	}
	return arr;
} 

void KMP(vector<string> texto, vector<string> buscar){
	int m = buscar.size();
	int n = texto.size();
	vector <int> indices;
	indices = indexCreation(buscar);
	int i=0,j=0;
	while(i < N){
		if(pat[j] == texto[i]){
			j++;
			i++;
		}
		if(j == M){
			cout << "Pattern found at index" << i-j;
		}
		else{
			if(i < N && pat[j] != texto[i]){
				if(j != 0){
					j = indices[j-1];
				}
				else{
					i++;
				}
			}
		}
	}
	return ;
}

void ingresoAlfabeto(vector<string> *alfabeto1,unordered_map<string,bool> *umap){
	bool b;
	string a;
	
	while(true){
		cin >> a;
		if(a == "&"){
			break;
		}
		else{
			(*alfabeto1).push_back(a);
			(*umap)[a] = true;
		}
	}
	return ;
}

void potencia(vector<string> w1,vector<string> w2){
	int p;
	cout << "Introduce la potencia: \n";
	cin >> p;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < w1.size(); ++j)
		{
			cout << w1[j];
		}
		for (int k = 0; k < w2.size(); ++k)
		{
			cout << w2[k];
		}
	} cout << "\n";
	return ;
}

void timesString(vector<string> word){
	int count=0;
	string s;
	cout << "Simbolo a buscar \n";
	cin >> s;
	for (int i = 0; i < word.size(); ++i)
	{
		if(word[i] == s){
			count++;
		}
	}
	cout << "Se repite " << count << " veces \n";
	return ;
}

bool check(vector<string> alpha,vector<string> p,  unordered_map<string,bool> umap){
	

	int i =0;
	bool flag = true;
	for (int j = 0; j < p.size();++j)
	{
		// si la llave no existe
		if (umap.count(p[j]) == 0) 
		//if(umap.find(p[j]) == umap.end())
		{
			cout << p[j] << " ";
			cout << "Error"<< "\n";
			flag = false;
			break;
		}
	}

	return flag;
}

vector<string> pedirString(vector<string> alpha,  unordered_map<string,bool> umap){
	bool b = true;
	vector<string> p;
	string a;
	
	do{	
		if(!b){
			p.clear();
		}
		while(true){
			cin >> a;
			if(a == "&"){
				break;
			}
			else{
				p.push_back(a);
			}
		}
		b = check(alpha,p,umap);
	}while(!b);
	return p;
}

void printElements(vector<string> v){
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
	return ;
}

vector<string> multiABC(vector<string> alpha, vector<string> beta){
	string aux;
	vector <string> r;
	for (int i = 0; i < alpha.size(); ++i)
	{
		for (int j = 0; j < beta.size(); ++j)
		{
			aux = alpha[i] + beta[j];
			r.push_back(aux);
		}
	}
	return r;
}

void powerABC(vector<string> alpha, string past, int pow,bool check){
	if(check){
		for (int i = 0; i < alpha.size(); ++i)
		{
			powerABC(alpha,alpha[i],pow-1,false);
		}
	}
	else{
		if(pow > 1){
			for (int i = 0; i < alpha.size(); ++i)
			{
				powerABC(alpha,past+alpha[i],pow-1,false);
			}
		}
		else{
			for (int i = 0; i < alpha.size(); ++i)
			{
				cout << past + alpha[i] << " ";
			}
			cout << "\n";
		}		
	}
	return ;
}

//Checar esta funcion

void filterPow(vector<string> alpha,int poten){
	vector<string> aux;
	string ayuda;
	int a=0, i=1;
	if(poten < 0){
		while((i-1)< alpha.size()){
			ayuda = alpha[alpha.size()-i];
			aux.push_back(ayuda);
			i++;
		}
		powerABC(aux," ",abs(poten),true);
	}
	else{
		powerABC(alpha," ",poten,true);
	}
}

int main(){
	vector<string> alfabeto1,alfabeto2;
	vector<string> p1,p2;
	int opc,pot;
	vector <string> resultado;
	unordered_map<string,bool> umap,umap2;
	vector<string> mandar;

	mandar.push_back("a");
	mandar.push_back("c");
	mandar.push_back("a");
	mandar.push_back("c");
	mandar.push_back("a");
	mandar.push_back("b");
	mandar.push_back("a");
	mandar.push_back("c");
	mandar.push_back("a");
	mandar.push_back("c");
	mandar.push_back("a");
	mandar.push_back("b");
	mandar.push_back("a");
	mandar.push_back("c");
	mandar.push_back("a");
	mandar.push_back("c");
	mandar.push_back("a");
	mandar.push_back("c");


	cout << "Ingresa el alfabeto 1: \n";
	//inciso a
	ingresoAlfabeto(&alfabeto1,&umap);
	cout << "Ingresa el alfabeto 2: \n";
	//inciso b
	ingresoAlfabeto(&alfabeto2,&umap2); 

	do{
		cout << "MENU\n"
		<<	"1.-Inciso c) (ingresar cadenas)\n"
		<<	"2.-Inciso d) (potencia de cadenas)\n"
		<<	"3.-Inciso e) (simbolo en cadena)\n"
		<<	"4.-Inciso f) (sufijo,prefijo)\n"
		<<	"5.-Inciso g) (potencia de alfabeto)\n"
		<<	"6.-Inciso h) (multi abc1 y abc2)\n"
		<<	"7.-Inciso i) (multi abc1 con abc2, con abc1) \n"
		<<	"8.- Terminar\n";
		cin >> opc;
		switch(opc){
			case 1:{
				//inciso c
				p1=pedirString(alfabeto1,umap);
				p2 = pedirString(alfabeto1,umap);
				break;
			}
			case 2:{
				//inciso d
				potencia(p1,p2);
				break;
			}
			case 3:{
				//inciso e
				timesString(p1);
				break;
			}
			case 4:{
				indexCreation(mandar);
			}
			case 5:{
				//inciso
				cin >> pot;
				filterPow(alfabeto1,pot);
				cout << "\nseparacion\n";
				break;
			}
			case 6:{
				//incisos h e i 
				resultado = multiABC(alfabeto1,alfabeto2);
				printElements(resultado);
				resultado.clear();
				break;
			}
			case 7:{
				resultado = multiABC(multiABC(alfabeto1,alfabeto2),alfabeto1);
				printElements(resultado);
				resultado.clear();
				break;
			}
		}
	}while(opc != 9);
	cout << "Goodbye rey";
	return 0;
}
