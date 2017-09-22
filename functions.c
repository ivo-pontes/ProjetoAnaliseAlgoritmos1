#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

void menu()
{
  int op = -1;

	do
	{
		printf("------------------MENU----------------------\n");
		printf("1 = Criar Todos os arquivos txt (100-1000000)\n");
    printf("2 = Algoritmo bubbleSort                     \n");
    printf("3 = Algoritmo InsertionSort                  \n");
    printf("4 = Algoritmo MergeSortSort                  \n");
    printf("5 = Algoritmo QuickSort                      \n");
		printf("0 = sair\n");
		printf("---------------------------------------------\n");
		scanf("%d", &op);
		printf("\n");

		switch (op)
		{
			case 1:
					createAllFiles();
			break;
			case 2:
          sort(100,2);
          sort(1000,2);
          sort(10000,2);
          sort(100000,2);
          sort(200000,2);
          //sort(1000000, 2);
			break;
      case 3:
          sort(100,3);
          sort(1000,3);
          sort(10000,3);
          sort(100000,3);
          sort(200000,3);
          //sort(500000,3);
      break;  
      case 4:
          sort(100,4);
          sort(1000,4);
          sort(10000,4);
          sort(100000,4);
          sort(200000,4);
          sort(500000,4);
      break;  
      case 5:
          sort(100,5);
          sort(1000,5);
          sort(10000,5);
          sort(100000,5);
          sort(200000,5);
          sort(500000,5);
      break;                    
			default:
          op = 0;
			break;
		}
	} while(op != 0);
}

void createAllFiles()
{
  createFiles(100);
  createFiles(1000);
  createFiles(10000);
  createFiles(50000);
  createFiles(100000);
  createFiles(200000);
  createFiles(500000);
  createFiles(1000000);
  printf("Arquivos criados.\n");
}

void createFiles(long int n)
{
  long int i;
  srand(time(NULL));   
  char filename[MAX_STR];
  snprintf(filename, MAX_STR, "%ld", n);
  strcat(filename,".txt");

  FILE * f;
  f = fopen (filename,"w+");
  if (f != NULL)
  {
    for (i = 0; i < n; i++)
    {
      fprintf(f, "%ld ",i+1);
    }

    fclose (f);
  }


  snprintf(filename, MAX_STR, "%ld",n);
  strcat(filename,"-shuffle.txt");

  FILE * fs;
  fs = fopen (filename,"w+");
  if (fs != NULL)
  {
    for (i = 0; i < n; i++)
    {
      fprintf(fs, "%ld ",rand() % (n+1));
    }

    fclose (fs);
  } 

  snprintf(filename, MAX_STR, "%ld",n);
  strcat(filename,"-reverse.txt");

  FILE * fr;
  fr = fopen (filename,"w+");
  if (fs != NULL)
  {
    for (i = n; i > 0; i--)
    {
      fprintf(fr, "%ld ",i);
    }

    fclose (fr);
  } 

}

void sort(long int length, long int metodo)
{
  long int v100[length];
  //v100 = malloc(100 * sizeof(int));

  openFiles(v100, length);

  clock_t start, end;
  double cpu_time_used;

  start = clock();

    switch (metodo)
    {
      case 1:
          createAllFiles();
      break;
      case 2:
          bubbleSort(v100, length);
      break;
      case 3:
          insertionSort(v100, length);
      break;  
      case 4:
          mergeSort(v100, 0, length-1);
      break;  
      case 5:
          quickSort(v100, 0, length-1);
      break;             
      default:
      break;
    }
    
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Tempo de uso do CPU, com %ld posições: %.2f.\n", length, cpu_time_used);
  
  //  printArray(v100, length);
}



void openFiles(long int *array,long int length )
{
  long int i = 0, j = 0;
  FILE *fp;
  char aux[30], c;     
  char filename[100];

  snprintf(filename, 100, "%ld",length);
  strcat(filename,"-shuffle.txt");

  fp = fopen(filename, "r");

  while(!feof(fp))
  {
    c = fgetc(fp);

    if ( c != ' ' && c != EOF)
    {
      aux[j] = c;
      j++;
    }else
    {
      aux[j] = '\0';
      j = 0;
      array[i] = atoi(aux);
      i++;
    }
  }

  fclose(fp);
}

void bubbleSort(long int *array,long int length )
{
   long int i, j, aux;   
   for( i = 0; i < length-1;  i++ )
      for( j= i+1; j < length ; j++ )  
         if( array[i] > array[j] )  
         {          
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
         }
}


void insertionSort(long int *array, long int length )
{
  if(length > 0)
  {
    insertionSort(array, length-1);
    long int aux = array[length];
    long int i = length-1;

    while( i >= 0 && array[i] > aux)
    {
      array[i+1] = array[i];
      i = i-1;
    }

    array[i+1] = aux;
  }
}

void mergeSort(long int *array,long int start,long int end ) 
{
  long int i,j,k,half,*aux;
  
  if ( start == end ) 
    return;
   
   // ordenacao recursiva das duas metades
   half = ( start+end )/2;
   mergeSort( array, start, half);
   mergeSort( array, half+1,end );

   // intercalacao no vetor temporario t
   i = start;
   j = half+1;
   k = 0;
   aux = (long int *) malloc(sizeof(long int) * (end-start+1));
   
   while( i<half+1 || j<end+1 )
   { 
      if ( i == half+1 )
      { // i passou do final da primeira metade, pegar v[j]
         aux[k] = array[j];
         j++;
         k++;
      } 
      else
      {
         if (j==end+1) 
         { 
            // j passou do final da segunda metade, pegar v[i]
            aux[k] = array[i];
            i++;
            k++;
         } 
         else 
         {
            if (array[i] < array[j]) 
            { // v[i]<v[j], pegar v[i]
               aux[k] = array[i];
               i++;
               k++;
            } 
            else
            { // v[j]<=v[i], pegar v[j]
              aux[k] = array[j];
              j++;
              k++;
            }
         }
      }
      
      

   }
   // copia vetor intercalado para o vetor original
   for( i=start; i<=end; i++ )
   {
      array[i] = aux[i-start];
   }
   free(aux);
}

long int partition(long int *array,long int start,long int end )
{
  long int x,i,j,aux;
  x = array[start];
  i = start - 1;
  j = end + 1;
   
  while(1)
  {
    do
    { 
      j--; 
    } while( array[j]>x );
    
    do 
    { 
      i++; 
    } while( array[i]<x );
    
    if (i<j) 
    {
       aux = array[i];
       array[i] = array[j];
       array[j] = aux;
    }
    else
    {
       return j;
    }
  }
}


void quickSort(long int *array,long int start,long int end )
{
   long int pivot;
   if (start < end) 
   {
      pivot = partition( array, start, end);
      quickSort( array, start, pivot);
      quickSort(array, pivot+1, end);
   }
}




void printArray(long int *array, long int length)
{
  long int i;
  printf("\nImprimindo vetor de %ld posições.\n\n", length);

  for (i = 0; i < length; i++)
    printf("%ld ", array[i]);

  printf("\n\n");
}


/*
  Função: printMakefile()
  Utiliza as funções getString() e getStringN() com exemplo.
*/
void printMakeFile()
{
  char * string;

  printf("Olá, qual seu nome?\n");
  string = getString();
  printf("Olá, %s, o arquivo compilado e executado usando makefile.\n", string);
  free(string);//Após usar a função getString() e antes de usar novamente, liberar a memória.
  printf("Digite outro nome.\n");
  string = getStringN(100);
  printf("String: %s, impressa com tamanho dinâmico.\n", string);
  free(string);
}

/*
  Função: getString()
  Utiliza a função scanf() para pegar o "input" do usuário e limpar o buffer da
  memória. Após retornar, deve-se liberar a memória da variável de mesmo nome(string)
*/
char * getString()
{
  char * string;
  string = malloc(MAX_STR * sizeof(string));
  scanf ("%[^\n]", string);
  fflush(stdin);
  __fpurge(stdin);
  return string;
}

/*
  Função: getStringN(length)
  Utiliza a função scanf() para pegar o "input" do usuário e limpar o buffer da
  memória. A diferença é que a memória é alocada de acordo com o parãmetro passado.
  Após retornar, deve-se liberar a memória da variável de mesmo nome(string)
*/
char * getStringN(int length)
{
  char * string;
  string = malloc(length * sizeof(string));
  scanf ("%[^\n]", string);
  fflush(stdin);
  __fpurge(stdin);
  return string;
}
