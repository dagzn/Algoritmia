#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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

void filterPow(vector<string> alpha,int pow){
	vector<string> aux;
	int a=0;
	if(pow < 0){

		for (int i = alpha.size()-1; i >= 0 ; i--)
		{
			aux[a] = alpha[i];
			a++;
		}
		powerABC(aux," ",abs(pow),true);
	}
	else{
		powerABC(alpha," ",pow,true);
	}
}

int main(){
	vector<string> alfabeto1,alfabeto2;
	vector<string> p1,p2;
	int opc;
	vector <string> resultado;
	unordered_map<string,bool> umap,umap2;
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

			}
			case 5:{
				//inciso g
				filterPow(alfabeto1,-1);
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