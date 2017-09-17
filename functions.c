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
		printf("2 = Opção 2\n");
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
					printf("Opção 2.\n");
			break;
			default:
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
  char filename[MAX_STR];
  snprintf(filename, MAX_STR, "%d", n);
  strcat(filename,".txt");

  FILE * f;
  f = fopen (filename,"a+");
  if (f != NULL)
  {
    for (int i = 0; i < n; i++)
    {
      fprintf(f, "%d ",i+1);
    }

    fclose (f);
  }
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
