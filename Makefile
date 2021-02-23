PROGRAM=test
CC=g++
CFLAGS=-Wall -pedantic -g
LDFLAGS=-lm


all:$(PROGRAM)

$(PROGRAM): main.o diccionario.o parser.o personaje.o agua.o fuego.o tierra.o aire.o
	$(CC) $(CFLAGS) -o $(PROGRAM) main.o diccionario.o parser.o personaje.o agua.o fuego.o tierra.o aire.o $(LDFLAGS) 

main.o: main.cpp diccionario.h personaje.h agua.h fuego.h tierra.h aire.h grafo.h
	$(CC) $(CFLAGS) -c main.cpp

diccionario.o: diccionario.cpp personaje.h bin_tree_node.h bin_search_tree.h
	$(CC) $(CFLAGS) -c diccionario.cpp

juego.o: juego.cpp juego.h interfazUsuario.h lectorCsv.h lista.h listaJugador.h
	$(CC) $(CFLAGS) -c juego.cpp

interfazUsuario.o: interfazUsuario.cpp agua.h fuego.h tierra.h aire.h interfazUsuario.h
	$(CC) $(CFLAGS) -c interfazUsuario.cpp

jugador.o: jugador.cpp jugador.h listaJugador.h nodoJugador.h
	$(CC) $(CFLAGS) -c jugador.cpp

grafo.o: grafo.cpp grafo.h casillero.h
	$(CC) $(CFLAGS) -c grafo.cpp

casillero.o: casillero.cpp casillero.h
	$(CC) $(CFLAGS) -c casillero.cpp

camino.o: camino.cpp camino.h personaje.h
	$(CC) $(CFLAGS) -c camino.cpp

nodoJugador.o: nodoJugador.cpp nodoJugador.h
	$(CC) $(CFLAGS) -c nodoJugador.cpp

listaJugador.o: listaJugador.cpp listaJugador.h jugador.h nodoJugador.h
	$(CC) $(CFLAGS) -c listaJugador.cpp

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