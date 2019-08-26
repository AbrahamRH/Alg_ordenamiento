#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int* y);
void print_vector(int* vector, int* n);
static void quick_asc(int* vector, int* first, int* last);
static void quick_desc(int* vector, int* first, int* last);
void Quick_sort(int* vector, int* tam, int* direccion);

int main(int argc, char** argv)
{
	if(argc < 3){								//S no seagregan los argumetos necesarios ermina el programa
		printf("\nParametro 1: Longitud\nParametro 2: Tipo de ordenacion\n\t1)ASCENDENTE\n\t2)DESCENDENTE\n");
		return -1;
	}
	int  valores   = atoi(argv[1]);
	int  direccion = atoi(argv[2]);
	int* vector    = (int*)malloc(sizeof(int)*valores);

	srand(time(NULL));
	for( size_t i = 0; i < valores ; ++i)
		vector[i] = rand()%100;
	
	printf("El vector desordenado es: \n");
	print_vector(vector,&valores);
	Quick_sort(vector, &valores, &direccion);
	printf("El vector ordenado es: \n");
	print_vector(vector,&valores);

}

void Quick_sort(int* vector, int* tam, int* direccion)
{
	int first = 0;

	if(*direccion == 1)
		quick_asc(vector, &first, tam);
	else if(*direccion == 2)
		quick_desc(vector, &first, tam);
	else
		printf("\nEsa opcion no es valida\n");
}

static void quick_desc(int* vector,int* first, int* last)
{
	int mid = (*first + *last) / 2;
	int piv = vector[mid];
	int  x0 = *first;
	int  x1 = *last;

	while(x0 <= x1){
		while( vector[x0] > piv )
			++x0;
		while( vector[x1] < piv )
			--x1;
		if( x0 <= x1 ){
			swap( &vector[x0], &vector[x1]);
			++x0;
			--x1;
		}
	}

	if( *first < x1 )
		quick_desc( vector, first, &x1 );
	if( x0 < *last )
		quick_desc( vector, &x0, last );
}

static void quick_asc(int* vector,int* first, int* last)
{
	int mid = (*first + *last) / 2;
	int piv = vector[mid];
	int  x0 = *first;
	int  x1 = *last;

	while(x0 <= x1){
		while( vector[x0] < piv )
			++x0;
		while( vector[x1] > piv )
			--x1;
		if( x0 <= x1 ){
			swap( &vector[x0], &vector[x1] );
			++x0;
			--x1;
		}
	}

	if( *first < x1 )
		quick_asc( vector, first, &x1 );
	if( x0 < *last )
		quick_asc( vector, &x0, last );
}


void print_vector(int* vector, int* n)
{
	for(size_t i = 0; i < *n ; ++i)
		printf("%3d",vector[i]);
	printf("\n");
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
