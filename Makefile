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
