main: main.o dictionary.o node.o
		g++ main.o dictionary.o node.o -o main

main.o: main.cpp
	g++ -c main.cpp

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp

node.o: node.cpp
	g++ -c node.cpp

clean:
	rm *.o main
