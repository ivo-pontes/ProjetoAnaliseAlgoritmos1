#ifndef _H_FUNCTIONS
#define _H_FUNCTIONS

#define MAX_STR 100

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
void selectionSort(long int *,long int,long int *);
long int partition(long int *,long int,long int, long int *);
void quickSort(long int *,long int,long int, long int *);
#endif
