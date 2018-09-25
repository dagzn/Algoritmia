//*****************************************************************
//EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//Curso: Análisis de algoritmos
//ESCUELA SUPERIOR DE CÓMPUTO - IPN
//(C) Marzo 2013
//Ejemplo del empleo de Threads
//Compilación: ""gcc -lm -lpthread -o ejemplo_thread ejemplo_thread.c"
//Ejecución: "./ejemplo_thread 4"
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int numThreads;			//Número de threads
int n;
int buscar[]={322486,14700764,3128036,6337399,61396,10393545,2147445644,1295390003,450057883,
187645041,1980098116,152503,5000,1493283650,214826,1843349527,1360839354,2109248666,2147470852,0};
int indice;
int *arr;

//********************************************************************************
//COMPORTAMIENTO DE LOS THREADS
//********************************************************************************

//********************************************************************************
//1 Saludar 
//********************************************************************************
void* saludar(void* id)
{
	printf("\nHola desde Saludar\tSoy el thread %d",(int)id);
}

//********************************************************************************
//2 Realizar un procesamiento
//********************************************************************************
void* procesar(void* id)
{	
	int n_thread=(int)id;
	int inicio,fin,i,a;

	//Revisar la parte de los datos a procesar	
	inicio=(n_thread*n)/numThreads;
	if(n_thread==numThreads-1)	
		fin=n;
	else
		fin=((n_thread+1)*n)/numThreads-1;

	//printf("\nHola desde procesar\tSoy el thread %d\tInicio %d\tTermino %d",n_thread,inicio,fin);
	printf("%d & %d & %d & ",n_thread,inicio,fin );
	
	int left=inicio,right=fin;
	int middle,res=-1;
	while((left <= right)){
		//cout << "hola\n";
		middle = (left+right)/2;
		if(arr[middle] == buscar[indice]){
			res=middle;
			break;
		}
		if(arr[middle] > buscar[indice])
			right=middle-1;
		else
			left=middle+1;
	}
	if(res>=0)
		printf("%d ##\n",res);
	else
		printf("No ##\n");

	//printf("\nBye desde procesar\tSoy el thread %d\tHe terminado",n_thread);
}

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char *argv[])
{	
	int i,j,k; 	//Variables auxiliares para loops
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	uswtime(&utime0, &stime0, &wtime0);
	pthread_t *thread;
	
	if (argc<2) 
	{
		printf("Indique el número de threads - \tEjemplo: [user@equipo]$ %s 4\n\n",argv[0]);
		exit(-1);
	}
	
	numThreads=atoi(argv[1]);
	thread = malloc(numThreads*sizeof(pthread_t));
	
	if (argc!=3) 
	{
		printf("\nIndique el tamaño de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	
	n=atoi(argv[2]);
	
	arr=(int *)realloc(ptr, sizeof(int)*n);

	for (int i = 0; i < n; ++i){
		scanf("%i",&arr[i]);
	}

	for(int a=0; a < 20;a++){
		//for(int b=0; b < 5; b++){
		//int numero=buscar[a];
		indice=a;
		//Crear los threads
		for (i=1; i<numThreads; i++) 
		{
			if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) 
			{
				perror("El thread no  pudo crearse");
				exit(-1);
			}
		}
		printf("Numero a buscar: %d Tamano de $n$: %d ##\n",buscar[indice],n);
		printf("#begin{table}[htbp]\n");
		printf("#begin{tabular}{lll}\n");
		printf("Hilo & Inicio & Fin & Encontrado ##\n",n_thread,inicio,fin );
		
		procesar(0);
		for (i=1; i<numThreads; i++) 
			pthread_join (thread[i], NULL);

		printf("#end{tabular}\n#end{table}\n");
		//Tiempos en latex
		uswtime(&utime1, &stime1, &wtime1);
		printf("#textbf{Tiempo total:} %.10f s ##\n",wtime1 - wtime0);
		printf("#textbf{Tiempo en CPU:} %.10f s ##\n",utime1 - utime0);
		printf("#textbf{Tiempo aprox. por cada hilo:} %.10f s ##[1cm]\n",(utime1 - utime0)/numThreads);
		//}
	}

	
	
	/*
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", numThreads,(utime1 - utime0)/numThreads);	
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	*/
	exit (0);	
}
