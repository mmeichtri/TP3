PROGRAM=test
CC=g++
CFLAGS=-Wall -pedantic -g
LDFLAGS=-lm


all:$(PROGRAM)

$(PROGRAM): main.o diccionario.o parser.o personaje.o agua.o fuego.o tierra.o aire.o
	$(CC) $(CFLAGS) -o $(PROGRAM) main.o diccionario.o parser.o personaje.o agua.o fuego.o tierra.o aire.o $(LDFLAGS) 

main.o: main.cpp diccionario.h personaje.h agua.h fuego.h tierra.h aire.h
	$(CC) $(CFLAGS) -c main.cpp 

diccionario.o: diccionario.cpp personaje.h bin_tree_node.h bin_search_tree.h
	$(CC) $(CFLAGS) -c diccionario.cpp

parser.o: parser.cpp parser.h utils.h
	$(CC) $(CFLAGS) -c parser.cpp

personaje.o: personaje.cpp personaje.h utils.h
	$(CC) $(CFLAGS) -c personaje.cpp

agua.o: agua.cpp agua.h personaje.h
	$(CC) $(CFLAGS) -c agua.cpp

fuego.o: fuego.cpp fuego.h personaje.h
	$(CC) $(CFLAGS) -c fuego.cpp

tierra.o: tierra.cpp tierra.h personaje.h
	$(CC) $(CFLAGS) -c tierra.cpp

aire.o: aire.cpp aire.h personaje.h
	$(CC) $(CFLAGS) -c aire.cpp
	
clean:
	rm -vf  *.o $(PROGRAM)