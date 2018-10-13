const int ALF = 52;
string cads[1002];
vector<bool> esta;
vector<int> igual;

struct AhoCorasick{
  int termina;
  AhoCorasick *err,*res;
  vector<AhoCorasick*> hijos;

  AhoCorasick(): hijos(ALF,NULL), termina(-1),err(NULL),res(NULL){}


  ~AhoCorasick(){
    for(int i = 0 ; i < ALF ; i ++)
      if(hijos[i]) delete(hijos[i]);
    if(err) delete(err);
    if(res) delete(res);
  }

};
typedef AhoCorasick* pAC;

int Conversion(char c){
  if(c >= 'a' && c <= 'z')
    return c-'a';
  return c-'A'+26;
}

void Agrega(pAC nodo, string s,int idx){
  int sig;
  for(int i = 0 ; i < s.size(); i ++){
    sig = Conversion(s[i]);
    if(! nodo -> hijos[sig]){
      nodo -> hijos[sig] = new AhoCorasick();
    }
    nodo = nodo -> hijos[sig];
  }
  if(nodo -> termina == -1){
    nodo -> termina = idx;
    igual[idx] = idx;
  } else {
    igual[idx] = nodo -> termina;
  }
}

void Errores(pAC nodo){
  queue<pAC>Cola;
  nodo -> res = nodo; 
  for(int i = 0; i < ALF; i ++){
    pAC &sig = nodo -> hijos[i];
    if(!sig) sig = nodo;
    else {
      Cola.push(sig);     
      sig -> err = nodo;
    }
  } 

  pAC aux = NULL;
  while(!Cola.empty()){
    nodo = Cola.front();
    Cola.pop();
    pAC sig = nodo -> err;
    if(sig -> termina != -1) nodo -> res = sig;
    else nodo -> res = sig -> res;
    for(int i = 0 ; i < ALF; i ++){     
      sig = nodo -> hijos[i];
      if(sig){
        aux = nodo -> err;
        while(!aux -> hijos[i])
          aux = aux -> err;
        aux = aux-> hijos[i];
        sig -> err = aux;
        Cola.push(sig); 
      }
    }   
  }

}

void Busca(pAC nodo, string s){
  int sigl;
  pAC aux = NULL , raiz = nodo;
  for(int i = 0 ; i < s.size(); i++){
    sigl = Conversion(s[i]);
    while(!nodo -> hijos[sigl])
      nodo = nodo -> err;
    nodo = nodo -> hijos[sigl];
    aux = nodo;
    while(aux != raiz){
      if( aux -> termina != -1) 
        esta[aux -> termina] = true;
      aux = aux -> res;
    }   
  }
}

int main(){
  int T;
  int N;
  string S;
  cin >> T ;

  for(int caso = 1 ; caso <= T; caso++){
    cin >> S; 
    cin >> N;
    esta = vector<bool>(N);
    igual = vector<int>(N);
    pAC AC = new AhoCorasick();
    for(int i = 0 ; i < N ; i ++){
      cin >> cads[i];
      Agrega(AC,cads[i],i);
    }
    Errores(AC);
    Busca(AC,S);
    for(int i = 0 ; i < N ;i ++){
      int j = igual[i];
      if(esta[j]) cout << "y\n";
      else cout << "n\n";
    }
    free(AC);
  }
  return 0;
}
