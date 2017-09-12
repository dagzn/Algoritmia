
#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> estados  = {"AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG", "GT", "GR", "HG", "JC", "MC",
                           "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ",
                           "YN", "ZS"};
string vocales = "AEIOU";
vector<string> consonantes = {"B", "C", "D", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "V", "W",
                            "X", "Y", "Z"};
string sexo = "HM";


int random(int min, int max) {
        return rand() % (max + 1 - min) + min;
    }

    string getEstado() {
        return estados[random(0, 31)];
    }


    string anadirCero(int n) {
        string ans;
        if (n < 10)
            ans = "0" + to_string(n);
        else
            ans = to_string(n);
        return ans;
    }

    string getFecha() {
        string ans;
        string aux = to_string(random(1950, 2017));
        string res;
        res += aux[2];
        res += aux[3];
        string year = res;
        string month = anadirCero(random(1, 12));
        string day = anadirCero(random(1, 28));
        ans = year + month + day;
        return ans;
    }

    char getSexo() {
        return sexo[random(0, 1)];
    }

string getCurp() {
        string curp;
        
        char ini1Apellido = (char) random(65, 90);
        curp += ini1Apellido;

        char pVocalInternapApellido = vocales[random(0, 4)];
        curp += pVocalInternapApellido;

        char ini2Apellido = (char) random(65, 90);
        curp += ini2Apellido;

        char iniNombre = vocales[random(0, 4)];
        curp += iniNombre;

        string fecha = getFecha();
        curp += fecha;

        char sexo = getSexo();
        curp += sexo;

        string estado = getEstado();
        curp += estado;

        string pConsoInternapApellido = consonantes[random(0, 20)];
        curp += pConsoInternapApellido;

        string pConsoInterna2Apellido = consonantes[random(0, 20)];
        curp += pConsoInterna2Apellido;

        string pConsoInternaNombre = consonantes[random(0, 20)];
        curp += pConsoInternaNombre;

        string clave = to_string(random(0, 9));
        curp += clave;

        string check = to_string(random(0, 9));
        curp += check;
        
        return curp;
    }

    


void ingresoAlfabeto(vector<string> *alfabeto1,unordered_map<string,bool> *umap){
	bool b,flag=false;
	int opc,as1,as2;
	string a,aux;
	char r1,r2;
	

	do{	
		cout << "\n1.-Introducir alfabeto por caracteres individuales\n";
		cout << "2.-Introducir alfabeto por rango de caracteres \n";
		cin >> opc;
		if(opc == 1){
			while(true){
				cin >> a;
				if(a == "&"){
					break;
				}
				else{
					if((*umap).count(a) != 0){
						flag = true;
					}
					else{
						(*alfabeto1).push_back(a);
						(*umap)[a] = true;
					}
				}
			}
			if (flag)
			{	
				cout << "\nNo se pueden repetir caracteres en un alfabeto \n";
				(*alfabeto1).clear();
				(*umap).clear();
				opc = 3;
				//ingresoAlfabeto(alfabeto1,umap);
			}
		}
		else if(opc == 2){
			cout << "Introduzca el rango de caracteres (inicial final)\n";
			cin >> r1 >> r2;
			as1 = (int)r1;
			as2 = (int) r2;
			//cout << as1 << as2 << endl;
			for (int i = as1; i <= as2; ++i)
			{
				aux = (char)i;
				//cout << aux << endl;
				(*alfabeto1).push_back(aux);
			}
		}
	}while(opc != 1 && opc != 2);
	
	
	return ;
}

vector<string> createLang(vector<string> abc,int p,int l){
	vector<string> lang;
	unordered_map<string,bool> check;
	string aux="";
	int colisiones=0;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < l; ++j)
		{
			aux += abc[rand() % (abc.size()-1)];
			//cout << aux<< endl;
		}
		//cout << "trono for"<<endl;
		if(check.count(aux) == 0){
			//cout << "la metio" <<endl;
			check[aux] = true;
			lang.push_back(aux);
		}
		else
			colisiones++;
		cout << aux << endl;
		aux = "";
	}
	if(colisiones > 0)
		cout << "Hubieron "<<colisiones << " colisiones \n";
	return lang;
}
void unite(vector<string> lang1,vector<string> lang2){
	unordered_map <string,bool> check;
	for (int i = 0; i < lang1.size(); ++i)
	{
		if(check.count(lang1[i]) == 0){
			check[lang1[i]] = true;
			cout << lang1[i] << " ";
		}
		
		if(check.count(lang2[i]) == 0){
			check[lang2[i]] = true;
			cout << lang2[i] << " ";
		}
		cout << "\n";
	}
	return ;
}

void concatenate(vector<string> lang1,vector<string> lang2){
	for (int i = 0; i < lang1.size(); ++i)
	{
		for (int j = 0; j < lang2.size(); ++j)
		{
			cout << lang1[i] + lang2[j] << " ";
		}
		cout << "\n";
	}
	return ;
}

void substract(vector<string> lang1,vector<string> lang2){
	unordered_map <string,bool> check;
	unordered_map <string,bool> nel;
	vector<string> resultado;
	bool siono=true;
	//cout << "truena primero" <<endl;
	for (int i = 0; i < lang1.size(); ++i)
	{
		check[lang1[i]] = true;
		//resultado.push_back(lang1[i]);
	}
	//cout << "truena segundo" <<endl;
	for (int i = 0; i < lang2.size(); ++i)
	{
		if (check.count(lang2[i]) != 0){
			//delete check.second
			nel[lang2[i]] = true;
		}
	}
	//cout << "truena tercero" <<endl;
	for (int i = 0; i < lang1.size(); ++i)
	{
		if (nel.count(lang1[i]) == 0)
		{
			siono=false;
			cout << lang1[i] << " ";
		}
		
	}
	if (siono)
	{
		cout << "Sin palabras"<<endl;
	}
	//cout << "que pedo"<<endl;
	return ;
}

void powerOne(vector<string> alpha){
	for (int i = 0; i < alpha.size(); ++i)
	{
		cout << alpha[i] << "\n";
	}
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
		if(abs(poten) == 1)
			powerOne(aux);
		else
			powerABC(aux," ",abs(poten),true);
	}
	else{
		if(poten == 1)
			powerOne(alpha);
		else
			powerABC(alpha," ",poten,true);
	}
}

int main(){
	vector<string> alfa,lang1,lang2;
	unordered_map<string,bool> mapita;
	int p,l,pot,opc;

	ingresoAlfabeto(&alfa,&mapita);
				
	do{
		cout << "MENU\n"
		<<	"1.-Generar los lenguajes de manera aleatoria\n"
		<<	"2.-Generar la union de L1 con L2\n"
		<<	"3.-Generar la concatenacion de L1 con L2\n"
		<<	"4.-Generar la resta de L1 menos L2\n"
		<<	"5.-Generar la resta de L2 menos L1\n"
		<<	"6.-Generar la potencia de algun lenguaje\n"
		<< 	"7.-Generar un CURP de manera aleatoria\n"
		<<	"8.- Terminar\n";
		cin >> opc;
		switch(opc){
			case 1:{
				//inciso c
				cout << "Introduzca el numero de palabras y la longitud de estas: \n";
				cin >> p >> l;
				cout << "Lenguaje 1: "<<endl;
				lang1=createLang(alfa,p,l);
				cout << "Lenguaje 2: " <<endl;
				lang2=createLang(alfa,p,l);
				break;
			}
			case 2:{
				unite(lang1,lang2);
				break;
			}
			case 3:{
				//inciso e
				concatenate(lang1,lang2);
				break;
			}
			case 4:{
				//indexCreation(mandar);
				substract(lang1,lang2);
				break;
			}
			case 5:{
				//inciso
				substract(lang2,lang1);
				break;
			}
			case 6:{
				//incisos h e i 
				cout << "Introduzca la potencia: \n";
				cin >> pot;
				filterPow(lang1,pot);
				break;
			}
			case 7:{
				cout << "El CURP es: "<< getCurp() << endl;
			}
		}
	}while(opc > 0 && opc < 8);
	cout << "Goodbye rey";

	
	return 0;
}