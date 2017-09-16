# makefile_basico

Esse é um projeto básico em c.
Basicamente existem 2 funções a getString() e getStringN(), onde é possível utilizar
a função scanf sem a necessidade de digitar toda vez aqueles símbolos e limpar a memória.

Existe um arquivo functions.c com todas as funções necessárias(utilize os includes aqui também)

```
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void printMakeFile()
{
  ...
}

char * getString()
{
  ...
}

char * getStringN(int length)
{
  ...
}

```

Existe um arquivo fuctions.h com seus headers.

```
#ifndef _H_FUNCTIONS
#define _H_FUNCTIONS

#define MAX_STR 100

void printMakeFile();
char * getString();
char * getStringN(int);

#endif
```

Existe um arquivo principal main.c

```
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
	printMakeFile();
	return(0);
}
```

Existe um arquivo Makefile.

```
### Makefile ###
all: functions
functions: functions.o main.o
# O compilador faz a ligação entre os dois objetos
	gcc -o utilizandoMakefile functions.o main.o
#-----> Distancia com o botão TAB ### e não com espaços
functions.o: functions.c
	gcc -o functions.o -c functions.c -W -Wall -pedantic -Wno-implicit
main.o: main.c functions.h
	gcc -o main.o -c main.c -W -Wall -pedantic -Wno-implicit
clean:
	rm -rf *.o
mrproper: clean
	rm -rf functions
```
No exemplo acima, utilizandoMakefile é o nome do executável, basta alterá-lo.

Comandos:

>make clean

Limpará os arquivos .o criados com o make.

>make

Compilará o código-fonte e gerará o executável.

Baseado em:
[Wikibooks/Makefiles](https://pt.wikibooks.org/wiki/Programar_em_C/Makefiles)
