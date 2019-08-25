/*Implementacion de algoritmo Merge sort*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iso646.h>
#include <stdbool.h>

void Print_vector(int* vector,int* n);
void Merge_sort(int* vector, int low, int high,int* direccion);
void merge_asc(int* vector, size_t low, size_t high, size_t mid);
void merge_desc(int* vector, size_t low, size_t high, size_t mid);

size_t g_conteo;

int main(int argc, char** argv)
{
    /*Si no se agrega un argumento termina el programa*/
    if ( argc < 3 ){                                            
        printf("\nParametro 1: longitud\nParametro 2: Tipo de ordenacion\n\t1)ASCENDENTE\n\t2)DESCENDENTE\n");
	    return -1;
    }

    int  valores   = atoi(argv[1]);
    int* vector    = (int*)malloc(sizeof(int)*valores);
    int  direccion = atoi(argv[2]);

    /*Se llena el vector de valores pseudo aleatorios*/
    srand(time(NULL));
    for( size_t i = 0 ; i < valores ; i++ )
         vector[i] = rand()%100;

    printf("El vector desordenado es: \n");
    Print_vector(vector, &valores);
    Merge_sort(vector,0,valores-1,&direccion);    
    printf("El vector ordenado es: \n");
    Print_vector(vector, &valores);
    printf("El numero de pasos fue: %li\n",g_conteo);
    free(vector);
}


void merge_asc(int* vector, size_t low, size_t high, size_t  mid)
{
    size_t i=low ,j=mid+1 ,k=low;
    int B[high];

    while(i <= mid and j <= high){
        g_conteo++;
        if(vector[i] < vector[j])
            B[k++] = vector[i++];
        else
            B[k++] = vector[j++];
    }
    
    while(i <= mid)
        B[k++] = vector[i++];
    while(j <= high)
        B[k++] = vector[j++];

    for(i = low;i <= high; i++)
        vector[i] = B[i];
}


void merge_desc(int* vector, size_t low, size_t high, size_t  mid)
{
    size_t i=low ,j=mid+1 ,k=low;
    int B[high];

    while(i <= mid and j <= high){
        g_conteo++;
        if(vector[i] > vector[j])
            B[k++] = vector[i++];
        else
            B[k++] = vector[j++];
    }

    while(i <= mid)
        B[k++] = vector[i++];
    while(j <= high)
        B[k++] = vector[j++];

    for(i = low;i <= high; i++)
        vector[i] = B[i];
}


void Merge_sort( int* vector, int low, int high, int* direccion )
{
    int mid = (low + high)/2;
    if( low < high )
    {
        Merge_sort(vector,low,mid, direccion);
        Merge_sort(vector,mid+1,high, direccion);
        if(*direccion == 1)
            merge_asc(vector,low,high,mid);
        else if(*direccion == 2)
            merge_desc(vector,low,high,mid);
        else
            printf("\nOpcion no encontrada\n");
    }

}


void Print_vector(int* vector,int* n)                        
{
    for(size_t i = 0;i < *n; i++)
	    printf("%3d",vector[i]);
    printf("\n");
}