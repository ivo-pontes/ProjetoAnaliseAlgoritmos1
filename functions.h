#ifndef _H_FUNCTIONS
#define _H_FUNCTIONS

#define MAX_STR 100
#define MAX_IMG 200000

typedef struct
{
	long int id;
	long int size;
	char *data;
} Img;

//Funções de Teste
void printMakeFile();
char * getString();
char * getStringN(int);

//Funções Principais
void createAllFiles();
void createFiles(long int);
void openFiles(long int *,long int, int);
void createDataReport(long int,long int,int, double , long int *);
void emptyFiles(long int, int);
void sort(long int ,long int, int);
void printArray(long int *, long int );

//Menu
void menu();

//Algoritmos de Ordenação
void bubbleSort(long int *,long int, long int *);
void insertionSort(long int *, long int, long int * );
void mergeSort( long int *,long int, long int, long int * );
void quickSort( long int *, long int, long int * );
void selectionSort(long int *,long int,long int *);

//Abrir Vetor com Imagens
void openImages(int, int);
void imgBubbleSort(Img *, int, long int *);
void imgInsertionSort(Img *, int, long int *);
void imgMergeSort( Img *, int, int, long int * );
void imgQuickSort(Img *, int, long int *);
void imgSelectionSort(Img *,int,long int *);
void imgSort(int, int , int, char *, char *,long int *);

#endif
