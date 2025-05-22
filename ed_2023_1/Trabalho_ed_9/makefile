#Arquivo MAKEFILE

CC = gcc
OPTIMIZATION_FLAGS = -Wall -Wextra -std=c11 

all: dataset

dataset: estruturas_de_dados.o main.o
	$(CC) $(OPTIMIZATION_FLAGS) $^ -o $@

estruturas_de_dados.o: estruturas_de_dados.c estruturas_de_dados.h
	$(CC) $(OPTIMIZATION_FLAGS) -c $< -o $@

main.o: main.c estruturas_de_dados.h
	$(CC) $(OPTIMIZATION_FLAGS) -c $< -o $@
	
valgrind: dataset
	valgrind --leak-check=full ./dataset

clean:
	rm -f *.o dataset




