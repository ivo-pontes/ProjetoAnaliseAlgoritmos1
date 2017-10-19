#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

void menu()
{
  int op = -1;
  int order = 0; 

  printf("Digite o tipo de Ordenação: 0-Crescente | 1-Randômica | 2-Decrescente\n");
  scanf("%d",&order);

  printf("\n------------------MENU----------------------\n");
  //printf("1 = Criar Todos os arquivos txt (100-1000000)\n");
  printf("1 = Algoritmo bubbleSort                     \n");
  printf("2 = Algoritmo InsertionSort                  \n");
  printf("3 = Algoritmo MergeSortSort                  \n");
  printf("4 = Algoritmo QuickSort                      \n");
  printf("5 = Algoritmo SelectionSort                  \n");
  printf("6 = Imprimir Gráficos                        \n");
  //printf("7 = Criar Todos os arquivos txt (100-1000000)\n");
  printf("0 = sair\n");
  printf("---------------------------------------------\n");
  scanf("%d", &op);
  printf("\n");



  switch (op)
  {
  	case 1:
        emptyFiles(1,order);
        sort(100,1,order);
        sort(1000,1,order);
        sort(10000,1,order);
        sort(100000,1,order);
        sort(200000,1,order);
        sort(500000,1,order);
        sort(1000000,1,order);
  	break;
    case 2:
        emptyFiles(2,order);
        sort(100,2,order);
        sort(1000,2,order);
        sort(10000,2,order);
        sort(100000,2,order);
        sort(200000,2,order);
        sort(500000,2,order);
        sort(1000000,2,order);
    break;  
    case 3:
        emptyFiles(3,order);
        sort(100,3,order);
        sort(1000,3,order);
        sort(10000,3,order);
        sort(100000,3,order);
        sort(200000,3,order);
        sort(500000,3,order);
        sort(1000000,3,order);
    break;  
    case 4:
        emptyFiles(4,order);
        sort(100,4,order);
        sort(1000,4,order);
        sort(10000,4,order);
        sort(100000,4,order);
        sort(200000,4,order);
        sort(500000,4,order);
        sort(1000000,4,order);
    break; 
    case 5:
        emptyFiles(5,order);
        sort(100,5,order);
        sort(1000,5,order);
        sort(10000,5,order);
        sort(100000,5,order);
        sort(200000,5,order);
        sort(500000,5,order);
        sort(1000000,5,order);
    break;
    case 6:
        system("gnuplot4-x11 -p scripts/ascending.gp ");
        system("gnuplot4-x11 -p scripts/random.gp ");
        system("gnuplot4-x11 -p scripts/decreasing.gp ");
    break;
    case 7:
        //createAllFiles();
        //openImages(1, order);//Método e Ordem
        //openImages(2, order);
        //openImages(3, order);
        //openImages(4, order);
        openImages(5, order);
    break;                     
  	default:
        op = 0;
  	break;
  }

}


void sort(long int length, long int metodo, int ordem)
{
  long int v100[length];
  long int compSwap[2]; //Posição 0 - n de comparações, 1 - n de trocas
  char tipoOrdem[100];

  if(ordem == 2)
    strcpy(tipoOrdem,"Decrescente");
  else if(ordem == 1)
    strcpy(tipoOrdem,"Randômica");
  else
    strcpy(tipoOrdem,"Crescente");

  openFiles(v100, length, ordem);

  clock_t start, end;
  double cpu_time_used;

  start = clock();

    switch (metodo)
    {
      case 1:
          bubbleSort(v100, length, compSwap);
      break;
      case 2:
          insertionSort(v100, length, compSwap);
      break;  
      case 3:
          compSwap[0] = 0;
          compSwap[1] = 0;
          mergeSort(v100, 0, length-1, compSwap);
      break;  
      case 4:
          quickSort(v100, length, compSwap);
      break;  
      case 5:
          selectionSort(v100, length, compSwap);
      break;                    
      default:
      break;
    }
    
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("CPU Time, com %ld posições(%s): %.2f.\n", length, tipoOrdem, cpu_time_used);
  printf("Comparações: %ld.\nTrocas: %ld.\n", compSwap[0], compSwap[1]); 
  createDataReport(length,metodo, ordem, cpu_time_used , compSwap);
  //  printArray(v100, length);
}

void openImages(method,order)
{
  FILE *fp;
  char *imgBuffer1 = 0;
  char *imgBuffer2 = 0;
  long int lengths[2];
  lengths[0] = 0;
  lengths[1] = 0;

  fp = fopen("BoatAT.png", "r");

  if(fp == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
  }else
  {
    fseek (fp, 0, SEEK_END);
    lengths[0] = ftell (fp);
    fseek (fp, 0, SEEK_SET);
    imgBuffer1 = malloc (lengths[0]);
    if (imgBuffer1)
    {
      fread (imgBuffer1, 1, lengths[0], fp);
    }
  }

  fclose(fp);

  fp = fopen("TheLichAT.png", "r");

  if(fp == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
  }else
  { 
    fseek (fp, 0, SEEK_END);
    lengths[1] = ftell (fp);
    fseek (fp, 0, SEEK_SET);
    imgBuffer2 = malloc (lengths[1]);
    if (imgBuffer2)
    {
      fread (imgBuffer2, 1, lengths[1], fp);
    }
  }

  fclose(fp);

  imgSort(method,100,order, imgBuffer1, imgBuffer2, lengths);
  imgSort(method,1000,order, imgBuffer1, imgBuffer2, lengths);
  imgSort(method,10000,order, imgBuffer1, imgBuffer2, lengths);
  imgSort(method,100000,order, imgBuffer1, imgBuffer2, lengths);

  //printf("id: %ld, size: %ld.\n", vetor[i].id, vetor[i].size);
 
}


void imgSort(int method, int length, int order, char *imgBuffer1, char *imgBuffer2,long int *size)
{
  Img vetor[length];
  int i;
  char tipoOrdem[100];

  if(order == 2)
    strcpy(tipoOrdem,"Decrescente");
  else if(order == 1)
    strcpy(tipoOrdem,"Randômica");
  else
    strcpy(tipoOrdem,"Crescente");

  /*
    Ordem Crescente
  */
  for(i = 0; i < length ; i++)
  {
    if(i%2 == 0)
    {
      vetor[i].data = malloc(size[0]);
      vetor[i].data = imgBuffer1;
      vetor[i].size = size[0];
    }else
    {
      vetor[i].data = malloc(size[1]);
      vetor[i].data = imgBuffer2;
      vetor[i].size = size[1];
    }

    if(order != 1)//!Random
      vetor[i].id = i;
    else
      vetor[i].id = rand() % (length);
  }



  /*
    Ordem Decrescente
  */
  if(order == 2)
  {
    int j = 0;
    for(i = length-1; i >= 0 ; i--)
    {
      vetor[j].id = i;
      j++;
      //printf("id: %ld, size: %ld.\n", vetor[j].id, vetor[i].size);
    }
  }




  long int compSwap[2]; //Posição 0 - n de comparações, 1 - n de trocas

  clock_t start, end;
  double cpu_time_used;

  start = clock();
    switch (method)
    {
      case 1:
          imgBubbleSort(vetor, length, compSwap);
      break;
      case 2:
          imgInsertionSort(vetor, length, compSwap);
      break;  
      case 3:
          compSwap[0] = 0;
          compSwap[1] = 0;
          imgMergeSort(vetor, 0, length-1, compSwap);
      break;  
      case 4:
          imgQuickSort(vetor, length, compSwap);
      break;  
      case 5:
          imgSelectionSort(vetor, length, compSwap);
      break;                      
      default:
      break;
    }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("CPU Time, com %d posições(%s): %.2f.\n", length, tipoOrdem, cpu_time_used);
  printf("Comparações: %ld.\nTrocas: %ld.\n", compSwap[0], compSwap[1]); 
}

void imgBubbleSort(Img *array,int length,long int *compSwap)
{
  compSwap[0] = 0;
  compSwap[1] = 0;

  Img aux;
  long int i, j;

  for( i = 0; i < length-1;  i++ )
    for( j= i+1; j < length ; j++ )  
    {
      compSwap[0]++;
      if( array[i].id > array[j].id )  
      {          
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
        compSwap[1]++;
      }
    }
}

void bubbleSort(long int *array,long int length,long int *compSwap)
{
  compSwap[0] = 0;
  compSwap[1] = 0;

  long int i, j, aux;   
  for( i = 0; i < length-1;  i++ )
    for( j= i+1; j < length ; j++ )  
    {
      compSwap[0]++;
      if( array[i] > array[j] )  
      {          
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;

        compSwap[1]++;
      }
    }

}

void selectionSort(long int *array,long int length,long int *compSwap)
{
    long int i, j, min;//posição com o valor mínimo
    int aux;
    compSwap[0] = 0;
    compSwap[1] = 0;

    for (i = 0; i < length-1; i++)
    {
        min = i;
        for (j = i + 1; j < length; j++)
        {
            compSwap[0]++;
            if (array[j] < array[min]) 
                min = j;
        }

        compSwap[0]++;
        if (min != i)
        {
            compSwap[1]++;
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }

}

void imgSelectionSort(Img *array,int length,long int *compSwap)
{
    long int i, j, min;//posição com o valor mínimo
    Img aux;
    compSwap[0] = 0;
    compSwap[1] = 0;

    for (i = 0; i < length-1; i++)
    {
        min = i;
        for (j = i + 1; j < length; j++)
        {
            compSwap[0]++;
            if (array[j].id < array[min].id) 
                min = j;
        }

        compSwap[0]++;
        if (min != i)
        {
            compSwap[1]++;
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }

}


void imgInsertionSort(Img *array, int length ,long int *compSwap)
{
  compSwap[0] = 0;
  compSwap[1] = 0;

  Img aux;
  long int i, j;

  for(j = 1; j < length; j++)
  {
    aux = array[j];
    i = j-1;
    
    while( i >= 0 && array[i].id > aux.id)
    {
      array[i+1] = array[i];
      i--;
      compSwap[0]++;
      compSwap[1]++;
    }

    array[i+1] = aux;
  }
}

void insertionSort(long int *array, long int length ,long int *compSwap)
{
  compSwap[0] = 0;
  compSwap[1] = 0;

  long int i, j, aux;

  for(j = 1; j < length; j++)
  {
    aux = array[j];
    i = j-1;
    
    while( i >= 0 && array[i] > aux)
    {
      array[i+1] = array[i];
      i--;
      compSwap[0]++;
      compSwap[1]++;
    }

    array[i+1] = aux;
  }
}

void imgMergeSort(Img *array,int start, int end, long int *compSwap)
{
  Img *aux;
  int i,j,k,half;
  
  if ( start == end ) 
    return;
   
   // ordenacao recursiva das duas metades
   half = ( start+end )/2;
   imgMergeSort( array, start, half, compSwap);
   imgMergeSort( array, half+1,end, compSwap);

   i = start;
   j = half+1;
   k = 0;
   aux = (Img *) malloc(sizeof(Img) * (end-start+1));
   
   while( i<half+1 || j<end+1 )
   { 
      compSwap[0]++;

      if ( i == half+1 )
      { 
         aux[k] = array[j];
         j++;
         k++;
         compSwap[1]++;
      } 
      else
      {
        if (j==end+1) 
        { 
          aux[k] = array[i];
          i++;
        } 
        else 
        {
          if (array[i].id < array[j].id) 
          { 
             aux[k] = array[i];
             i++;
          } 
          else
          { 
            aux[k] = array[j];
            j++;
          }
          compSwap[0]++;
        }

        k++;
        compSwap[0]++;
        compSwap[1]++;
      }
      
      compSwap[0]++;
   }

   // copia vetor intercalado para o vetor original
   for( i=start; i<=end; i++ )
   {
      compSwap[1]++;

      array[i] = aux[i-start];
   }
   free(aux);
}

void mergeSort(long int *array,long int start,long int end, long int *compSwap)
{
  long int i,j,k,half,*aux;
  

  if ( start == end ) 
    return;
   
   // ordenacao recursiva das duas metades
   half = ( start+end )/2;
   mergeSort( array, start, half, compSwap);
   mergeSort( array, half+1,end, compSwap);

   i = start;
   j = half+1;
   k = 0;
   aux = (long int *) malloc(sizeof(long int) * (end-start+1));
   
   while( i<half+1 || j<end+1 )
   { 
      compSwap[0]++;

      if ( i == half+1 )
      { 
         aux[k] = array[j];
         j++;
         k++;
         compSwap[1]++;
      } 
      else
      {
        if (j==end+1) 
        { 
          aux[k] = array[i];
          i++;
        } 
        else 
        {
          if (array[i] < array[j]) 
          { 
             aux[k] = array[i];
             i++;
          } 
          else
          { 
            aux[k] = array[j];
            j++;
          }
          compSwap[0]++;
        }

        k++;
        compSwap[0]++;
        compSwap[1]++;
      }
      
      compSwap[0]++;
   }

   // copia vetor intercalado para o vetor original
   for( i=start; i<=end; i++ )
   {
      compSwap[1]++;

      array[i] = aux[i-start];
   }
   free(aux);
}

void imgQuickSort(Img *array,int length,long int *compSwap)
{
  compSwap[0] = 0;
  compSwap[1] = 0;

  Img aux;
  long int i, j;

  for (i = 1 ;i < length;i++) 
  {
    j = i;
 
    compSwap[0]++;
    while (array[j].id < array[j-1].id) 
    {
      compSwap[1]++;
      aux = array[j];
      array[j]   = array[j-1];
      array[j-1] = aux;
      j--;
    
      if (j == 0) 
       break;  
    }
  }
}



void quickSort(long int *array, long int length,long int *compSwap)
{
  compSwap[0] = 0;
  compSwap[1] = 0;

  long int i, j, aux;

  for (i = 1 ;i < length;i++) 
  {
    j = i;
    
    compSwap[0]++;
    while (array[j] < array[j-1]) 
    {
      compSwap[1]++;
      aux = array[j];
      array[j]   = array[j-1];
      array[j-1] = aux;
      j--;
    
      if (j == 0) 
       break;  
    }
  }
}


void openFiles(long int *array,long int length, int orderType)
{
  long int i = 0, j = 0;
  FILE *fp;
  char aux[30], c;     
  char filename[100];
  char order[100];

  if(orderType == 2)
    strcpy(order,"-decreasing.txt");
  else if(orderType == 1)
    strcpy(order,"-random.txt");
  else
    strcpy(order,"-ascending.txt");

  char strSize[100];
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  strcpy(filename, cwd);  
  strcat(filename,"/files/");
  
  snprintf(strSize, 100, "%ld",length);
  strcat(filename,strSize);
  strcat(filename,order);

  printf("%s.\n",filename);

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

void printArray(long int *array, long int length)
{
  long int i;
  printf("\nImprimindo vetor de %ld posições.\n\n", length);

  for (i = 0; i < length; i++)
    printf("%ld ", array[i]);

  printf("\n\n");
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

void emptyFiles(long int method, int order)
{
  srand(time(NULL));
  char filename[2014];   
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  strcpy(filename, cwd);
  char orderType[100]; 
  char orderMethod[100];

  if(order == 2)
    strcpy(orderType, "/data/decreasing/");
  else if(order == 1)
    strcpy(orderType, "/data/random/");
  else
    strcpy(orderType, "/data/ascending/");

  if(method == 1)
    strcpy(orderMethod, "bubbleSort");
  else if(method == 2)
    strcpy(orderMethod, "insertionSort");
  else if(method == 3)
    strcpy(orderMethod, "mergeSort");
  else if(method== 4)
    strcpy(orderMethod, "quickSort");      
  else if(method== 5)
    strcpy(orderMethod, "selectionSort");      
  else
    strcpy(orderMethod, "bubbleSort");

  strcat(filename,orderType);
  strcat(filename,orderMethod);
  strcat(filename, ".dat");
  printf("%s.\n",filename);
  FILE * f;
  f = fopen (filename,"w+");
  if (f != NULL)
  {
    fprintf(f, "\"%s\"\n",orderMethod);
    fclose (f);
  }

  if(order == 2)
    strcpy(orderType, "/data/");
  else if(order == 1)
    strcpy(orderType, "/data/");
  else
    strcpy(orderType, "/data/");

  strcpy(filename, cwd);
  strcat(filename, orderType);
  strcat(filename, orderMethod);
  strcat(filename, ".dat");

  FILE * fx;
  fx = fopen (filename,"ab+");
  if (fx != NULL)
  {
    fprintf(fx, "Comparações\t Trocas\n");
    fclose (fx);
  } 

}


void createDataReport(long int length,long int method, int order, double cpu_time, long int *compSwap)
{
  srand(time(NULL));
  char filename[2014];   
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  strcpy(filename, cwd);
  char orderType[100]; 
  char orderMethod[100];

  if(order == 2)
    strcpy(orderType, "/data/decreasing/");
  else if(order == 1)
    strcpy(orderType, "/data/random/");
  else
    strcpy(orderType, "/data/ascending/");

  if(method == 1)
    strcpy(orderMethod, "bubbleSort");
  else if(method == 2)
    strcpy(orderMethod, "insertionSort");
  else if(method == 3)
    strcpy(orderMethod, "mergeSort");
  else if(method== 4)
    strcpy(orderMethod, "quickSort"); 
  else if(method== 5)
    strcpy(orderMethod, "selectionSort");           
  else
    strcpy(orderMethod, "bubbleSort");

  strcat(filename,orderType);
  strcat(filename,orderMethod);
  strcat(filename, ".dat");
  printf("%s.\n",filename);
  FILE * f;
  f = fopen (filename,"ab+");
  if (f != NULL)
  {
    fprintf(f, "%ld %.2f\n",length, cpu_time);
    fclose (f);
  }

  if(order == 2)
    strcpy(orderType, "/data/");
  else if(order == 1)
    strcpy(orderType, "/data/");
  else
    strcpy(orderType, "/data/");

  strcpy(filename, cwd);
  strcat(filename, orderType);
  strcat(filename, orderMethod);
  strcat(filename, ".dat");

  FILE * fx;
  fx = fopen (filename,"ab+");
  if (fx != NULL)
  {
    fprintf(fx, "%ld %ld\n",compSwap[0], compSwap[1]);
    fclose (fx);
  }

}

void createFiles(long int n)
{
  long int i;
  srand(time(NULL));   
  char filename[MAX_STR];
  snprintf(filename, MAX_STR, "%ld", n);
  strcat(filename,"-ascending.txt");

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
  strcat(filename,"-random.txt");

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
  strcat(filename,"-decreasing.txt");

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
