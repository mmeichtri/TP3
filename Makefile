PROGRAM=test
CC=g++
CFLAGS=-Wall -pedantic -g
LDFLAGS=-lm


all:$(PROGRAM)

$(PROGRAM): main.o lecturaCsvCasilleros.o menuPrincipal.o matriz.o grafo.o diccionario.o \
archivoPersonaje.o juego.o interfazUsuario.o casillero.o \
parser.o personaje.o agua.o fuego.o tierra.o aire.o camino.o lago.o montania.o vacio.o volcan.o precipicio.o \
argumentos.o
	$(CC) $(CFLAGS) -o $(PROGRAM) main.o lecturaCsvCasilleros.o menuPrincipal.o matriz.o grafo.o diccionario.o \
	archivoPersonaje.o juego.o interfazUsuario.o casillero.o parser.o \
	personaje.o agua.o fuego.o tierra.o aire.o camino.o lago.o montania.o vacio.o volcan.o precipicio.o \
	argumentos.o $(LDFLAGS) 

main.o: main.cpp lecturaCsvCasilleros.h menuPrincipal.h matriz.h grafo.h diccionario.h argumentos.h
	$(CC) $(CFLAGS) -c main.cpp

lecturaCsvCasilleros.o: lecturaCsvCasilleros.cpp lecturaCsvCasilleros.h grafo.h lago.h montania.h precipicio.h vacio.h camino.h volcan.h matriz.h
	$(CC) $(CFLAGS) -c lecturaCsvCasilleros.cpp

menuPrincipal.o: menuPrincipal.cpp juego.h grafo.h matriz.h interfazUsuario.h diccionario.h archivoPersonaje.h personaje.h
	$(CC) $(CFLAGS) -c menuPrincipal.cpp

matriz.o: matriz.cpp matriz.h grafo.h casillero.h
	$(CC) $(CFLAGS) -c matriz.cpp

grafo.o: grafo.cpp grafo.h casillero.h
	$(CC) $(CFLAGS) -c grafo.cpp

diccionario.o: diccionario.cpp personaje.h bin_tree_node.h bin_search_tree.h
	$(CC) $(CFLAGS) -c diccionario.cpp

archivoPersonaje.o: archivoPersonaje.cpp archivoPersonaje.h diccionario.h agua.h fuego.h tierra.h aire.h personaje.h
	$(CC) $(CFLAGS) -c archivoPersonaje.cpp

juego.o: juego.cpp juego.h interfazUsuario.h agua.h fuego.h aire.h tierra.h diccionario.h grafo.h matriz.h
	$(CC) $(CFLAGS) -c juego.cpp

interfazUsuario.o: interfazUsuario.cpp agua.h fuego.h tierra.h aire.h interfazUsuario.h
	$(CC) $(CFLAGS) -c interfazUsuario.cpp

casillero.o: casillero.cpp casillero.h
	$(CC) $(CFLAGS) -c casillero.cpp

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

camino.o: camino.cpp camino.h personaje.h
	$(CC) $(CFLAGS) -c camino.cpp

lago.o: lago.cpp lago.h casillero.h
	$(CC) $(CFLAGS) -c lago.cpp

montania.o: montania.cpp montania.h casillero.h
	$(CC) $(CFLAGS) -c montania.cpp

vacio.o: vacio.cpp vacio.h casillero.h
	$(CC) $(CFLAGS) -c vacio.cpp

volcan.o: volcan.cpp volcan.h casillero.h
	$(CC) $(CFLAGS) -c volcan.cpp

precipicio.o: precipicio.cpp precipicio.h casillero.h
	$(CC) $(CFLAGS) -c precipicio.cpp
	
argumentos.o: argumentos.cpp argumentos.h
	$(CC) $(CFLAGS) -c argumentos.cpp

clean:
	rm -vf  *.o $(PROGRAM)