struct WaveletTree
{
	int lo, hi;//lo: el minimo valor en nuestra subsecuencia y hi: el mayor valor.
	WaveletTree *left, *right;//Apuntadores a nuestros hijos izquierdo y derecho.
	vector<int> mapLeft;//Vector que contendra todos los mapLeft que necesitemos
	vector<int> sumLeft;

	//queries indexed in base 1, complexity for all queries: O(log(max_element))
	//build from [from, to) with non-negative values in range [x, y]
	//you can use vector iterators or array pointers
	/*
		from: iterador que apunta hacia el inicio de la subsecuencia
		to: iterador que apunta hacia el fin de la subsecuencia
		lo: valor minimo
		hi: valor maximo
	*/
	WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int x, int y):lo(x),hi(y){
		if(from >= to) 
			return;
		//	Calculamos nuestro m, valor que ayudara a dividir la subsecuencia
		int m = (lo + hi) >> 1;
		//Esta funcion nos indica si el parametro x es menor o igual a nuestra m previamente calculada
		auto f = [m](int x){
			return x <= m;
		};

		//	Reservamos la cantidad(numero de elementos en el rango) necesaria para nuestro arreglo de mapLeft.
		mapLeft.reserve(to - from + 1);
		//	Como indexamos en 1, anadimos un cero para obviar el mapLeft[0]=0.
		mapLeft.push_back(0);
		

		for(auto it = from; it != to; ++it){
			/*
				*it: El valor de la posicion en la que esta el iterador
				Al llamar a la funcion f() con el parametro *it, esta nos devolvera un 1 si el parametro
				es menor o igual a nuestra m, y un 0 si no lo es.
			*/
			auto leq = f(*it);//leq: Less than or equal
			//	Al valor de leq que obtengamos le anadiremos el ultimo valor agregado a nuestro mapLeft. 
			//	Iremos acumulando los valores.
			mapLeft.push_back(mapLeft.back() + leq);
		}
		/*
			Si hi!=lo esto significa que nuestra subsecuencia tiene dos o mas valores distintos.
			Por lo tanto, debemos crear a nuestros nodos hijos ya que todavia no llegamos a un nodo hoja.
		*/
		if(hi != lo){
			/*
				A la funcion stable_partition le mandamos como parametros
				from: el iterador al inicio de nuestra subsecuencia
				to: el iterador al fin de nuestra subsecuencia
				f: una funcion de comparacion que necesita para dividir los elementos de manera adecuada

				La funcion dividira la subsecuencia en dos partes, sin alterar el orden en el que aparecen. 
				Los elementos menores o iguales a nuestro m se iran a nuestro hijo izquierdo y los demas al derecho.
				stable_partition regresa un iterador al primer elemento de la segunda parte.

				pivot:iterador al primer elemento de los elementos mayores a m
			*/
			auto pivot = stable_partition(from, to, f);
			//	Creamos a nuestro hijo izquierdo con los valores hasta pivot(menores o iguales a m)
			//	y definimos a m como su hi
			left = new WaveletTree(from, pivot, lo, m);
			//	Creamos a nuestro hijo derecho con los valores despues del pivot
			//	y definimos a m+1 como su lo
			right = new WaveletTree(pivot, to, m + 1, hi);
		}
	}
	/*
		NOTA IMPORTANTE
		En esta implementacion no es necesario calcular el mapRight para cada indice de cada subsecuencia.
		Si ya tenemos el mapLeft, podemos saber que mapRight = index - mapLeft(S,index).
		Por lo que la cantidad de elementos en el rango [l,r] que iran a la derecha sera igual a:
		(r-rb) - (l-lb)
	*/

	//Encontrar el k-esimo elemento de ese rango
	int kth(int l, int r, int k){
		//	Si estamos en un rango que no es valido
		if(l > r) 
			return -1;
		//	Si llegamos a un nodo hoja entonces nuestro resultado es el valor en ese nodo
		if(lo == hi) 
			return lo;
		int lb = mapLeft[l - 1], rb = mapLeft[r];
		//	inLeft es la cantidad de elementos en el rango [l,r] que iran a la izquierda
		//	Esto se calcula mediante la resta: mapLeft[r] - mapLeft[l-1]
		int inLeft = rb - lb;
		//	Si nuestra cantidad de numeros en inLeft es mayor a nuestra k, iremos a la izquierda
		//	y nuestros indices ahora seran mapLeft[l-1]+1 y mapLeft[r]
		if(k <= inLeft) 
			return left->kth(lb + 1, rb, k);
		else 
			return right->kth(l - lb, r - rb, k - inLeft);
	}

	//number of elements less than or equal to x in [l, r]
	int lessThanOrEqual(int l, int r, int x){
		if(l > r || x < lo) 
			return 0;
		if(hi <= x) 
			return r - l + 1;

		int lb = mapLeft[l - 1], rb = mapLeft[r];

		return left->lessThanOrEqual(lb + 1, rb, x) + right->lessThanOrEqual(l - lb, r - rb, x);
	}

	// sum of elements less than or equal to x in [l, r]
	int sumLessThanOrEqual(int l, int r, int x){
		if(l > r || x < lo) 
			return 0;
		if(hi <= x) 
			return sumLeft[r] - sumLeft[l-1];

		int lb = mapLeft[l - 1], rb = mapLeft[r];

		return left->sumLessThanOrEqual(lb + 1, rb, x) + right->sumLessThanOrEqual(l - lb, r - rb, x);
	}

	int sumElementsInRange(int l, int r, int a,int b){
		if(l > r || (a < lo && b < lo) || (a > hi && b > hi)){
			return 0;
		}
		if(a <= lo && b >= hi){
			return sumLeft[r] - sumLeft[l-1];
		}
		int lb = mapLeft[l - 1], rb = mapLeft[r];
		return left->sumElementsInRange(lb + 1, rb, a, b) + right->sumElementsInRange(l - lb, r - rb, a, b);
	}

	int elementsInRange(int l, int r, int a,int b){
		if(l > r || (a < lo && b < lo) || (a > hi && b > hi)){
			return 0;
		}
		if(a <= lo && b >= hi){
			return r - l + 1;
		}
		int lb = mapLeft[l - 1], rb = mapLeft[r];
		return left->elementsInRange(lb + 1, rb, a, b) + right->elementsInRange(l - lb, r - rb, a, b);
	}

	//number of elements equal to k in [l, r]
	int equalTo(int l, int r, int k){
		//	Si estamos en un rango no valido o nuestro k no se encuentra en esa subsecuencia, nos regresamos
		if(l > r || k < lo || k > hi) 
			return 0;
		//	Cuando lleguemos al nodo hoja indicado regresaremos la cantidad de elementos en el
		if(lo == hi) 
			return r - l + 1;

		int lb = mapLeft[l - 1], rb = mapLeft[r];
		//	Calculamos el m del nodo
		int m = (lo + hi) / 2;
		// Si nuestro numero a buscar es menor a nuestro m, iremos a la izquierda
		if(k <= m) 
			return left->equalTo(lb + 1, rb, k);
		else 
			return right->equalTo(l - lb, r - rb, k);
	}
};

//WaveletTree w(a.begin(), a.end(),*min_element(a.begin(), a.end()),*max_element(a.begin(), a.end()));