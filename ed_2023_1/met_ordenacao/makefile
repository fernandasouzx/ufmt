all: lista.o ordenacao.o 
	gcc main_lista.c lista.o ordenacao.o -o ed

lista.o: lista.c
	gcc -c lista.c

ordenacao.o: ordenacao.c
	gcc -c ordenacao.c

clean:
	rm *.o ed