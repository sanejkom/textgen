textgen: main.o tree.o gen.o czytaj.o
	$(CC) -o ../bin/textgen  main.o tree.o gen.o czytaj.o -Wall -ggdb

main.o: wejscie.h tree.h gen.h main.c
	$(CC) -c main.c -Wall -ggdb

tree.o: tree.h tree.c
	$(CC) -c tree.c -Wall -ggdb

gen.o: gen.h gen.c
	$(CC) -c gen.c -Wall -ggdb

czytaj.o: wejscie.h czytaj.c
	$(CC) -c czytaj.c -Wall -ggdb

.PHONY: clean

clean:
	-rm ./*.o ../bin/textgen

