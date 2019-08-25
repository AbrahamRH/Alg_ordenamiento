/*Implemetacion del algoritmo Bubble Sort optimizado*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void swap(int* x ,int* y);
void Print_vector(int* vector,int* n);
static void bubble_asc(int* vector,int* n);
static void bubble_desc(int* vector,int* n);
void Bubble_sort(int* vector,int* n,int* direccion);

size_t g_conteo = 0;

int main(int argc,char** argv)
{
    if (argc < 3){                                         		   //Si no se agrega un argumento termina el programa
        printf("\nParametro 1: longitud\nParametro 2: Tipo de ordenacion\n\t1)ASCENDENTE\n\t2)DESCENDENTE\n");
	    return -1;
    }

    int  valores   = atoi(argv[1]);
    int  direccion = atoi(argv[2]);
    int* vector    = (int*)malloc(sizeof(int)*valores);             //Se aparta el espacio suficiente de memoria para el arreglo

    srand(time(NULL));                                              //Crea numeros pseudoaleatorios
    for(size_t i = 0; i < valores ; i++)
	    vector[i] = rand()%100; 

    printf("El vector desordenado es: \n");
    Print_vector(vector, &valores);
    Bubble_sort(vector,&valores,&direccion);
    printf("El vector ordenado es: \n");
    Print_vector(vector,&valores);
    printf("El numero de pasos fue: %li\n",g_conteo);
    free(vector);                                                    //Se libera el espacio de memoria
    return 0;
}

void swap(int* x ,int* y)
{                                                                    //Función para hacer un intercambio de variables usando puntadores
    int temp = *x;
    *x = *y;
    *y = temp;
}

static void bubble_asc(int* vector,int* n)                           //Algoritmo bubble sort
{
    bool bandera;
    for(size_t j=0; j <*n-1;j++)                                     //Recorre el todos los elementos del arreglo
    {
        bandera = false;                                             //La bandera e usa para saber si el arreglo estaba ordenado previamente
	    for(size_t i = 0;i < (*n-1);i++)
	        if(vector[i] > vector[i + 1])
            {
		        swap(&vector[i],&vector[i+1]);
                bandera = true;
                g_conteo++;
            }
        if(bandera == false)                                         //Si estaba ordenado previamente se sale del programa
            break;
    }
}

static void bubble_desc(int* vector,int* n)                          //Algoritmo bubble sort
{
    bool bandera;
    for(size_t j=0; j <*n-1;j++)                                     //Recorre el todos los elementos del arreglo
    {
        bandera = false;                                             //La bandera e usa para saber si el arreglo estaba ordenado previamente
	    for(size_t i = 0;i < (*n-1);i++)
	        if(vector[i] < vector[i + 1])
            {
		        swap(&vector[i],&vector[i+1]);
                bandera = true;
                g_conteo++;
            }
        if(bandera == false)                                         //Si estaba ordenado previamente se sale del programa
            break;
    }
}

void Bubble_sort(int* vector,int* n,int* direccion)
{
    if(*direccion == 1)
        bubble_asc(vector, n);
    else if(*direccion == 2)
        bubble_desc(vector, n);
    else
        printf("\nOpcion no encontrada\n");
}

void Print_vector(int* vector,int* n)                        
{
    int i;
    for(i = 0;i < *n; i++)
	    printf("%3d",vector[i]);
    printf("\n");
}
