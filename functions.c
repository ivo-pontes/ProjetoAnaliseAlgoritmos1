#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void menu()
{
  int op = -1;

	do
	{
		printf("------------------MENU----------------------\n");
		printf("1 = Criar Todos os arquivos txt (100-1000000)\n");
    printf("2 = Algoritmo bubbleSort                     \n");
		printf("# = Opção #\n");
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
          callBubbleSort();
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
  createFiles(1000000);
  printf("Arquivos criados.\n");
}

void createFiles(n)
{
  int i;
  srand(time(NULL));   
  char filename[MAX_STR];
  snprintf(filename, MAX_STR, "%d", n);
  strcat(filename,".txt");

  FILE * f;
  f = fopen (filename,"a+");
  if (f != NULL)
  {
    for (i = 0; i < n; i++)
    {
      fprintf(f, "%d ",i+1);
    }

    fclose (f);
  }


  snprintf(filename, MAX_STR, "%d",n);
  strcat(filename,"-shuffle.txt");

  FILE * fs;
  fs = fopen (filename,"w+");
  if (fs != NULL)
  {
    for (i = 0; i < n; i++)
    {
      fprintf(fs, "%d ",rand() % 101);
    }

    fclose (fs);
  } 

  snprintf(filename, MAX_STR, "%d",n);
  strcat(filename,"-reverse.txt");

  FILE * fr;
  fr = fopen (filename,"w+");
  if (fs != NULL)
  {
    for (i = n; i > 0; i--)
    {
      fprintf(fr, "%d ",i);
    }

    fclose (fr);
  } 

}

void callBubbleSort()
{
  int v100[100];
  //v100 = malloc(100 * sizeof(int));

  openFiles(v100, 100);
  bubbleSort(v100, 100);
  printArray(v100, 100);


}

void openFiles(int *array,int length )
{
  int i = 0, j = 0;
  FILE *fp;
  char aux[30], c;     
  char filename[100];

  snprintf(filename, 100, "%d",length);
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

void bubbleSort(int *array,int length )
{
   int i, j, aux;   
   for( i = 0; i < length-1;  i++ )
      for( j= i+1; j < length ; j++ )  
         if( array[i] > array[j] )  
         {          
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
         }

}


void printArray(int *array, int length)
{
  int i;
  printf("\nImprimindo vetor de %d posições.\n\n", length);

  for (i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }

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
