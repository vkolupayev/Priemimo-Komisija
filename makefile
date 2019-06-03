all: head.o deka.o
	gcc deka.o head.o -o dekas
head.o: head.c
	gcc -c head.c -o head.o
deka.o: deka.c 
	gcc -c deka.c -o deka.o
clean: 
	rm *.o
