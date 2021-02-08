#ifndef QUEUE_H
#define QUEUE_H

#include "node_double.h"
#include <iostream>


using namespace std;


template <typename T>

class Queue{
	//This structure is implemented as a double linked list.
	//
	//In queue abstract-data-type, only non-extern nodes must have both pointers to previous and next
	//elements set to their respectives nodes.
	//First element in the queue, due to be the first one must point foward to NULL, while
	//so must the last element in backward.
	//
	//Tanto el primer como el último elemento de la cola deben apuntar a NULL en el sentido a
	//sus respectivos extremos. Sólo los nodos intermedios deben apuntar en ambos sentidos hacia
	//sus correspondientes antecesores y sucesores.
	//
	private:
		NodeD<T> *_first;
		NodeD<T> *_last;
		size_t _size;

	public:
		Queue();
		Queue(T data);
		~Queue();

		//Getters

		T first();
		//Shows the first element in the queue.
		//Muestra el primer elemento de la cola (el que sería devuelto en caso de usar dequeue).
		//
		T last();
		//Shows the last element in the queue.
		//Muestra el último elemento de la cola.
		//
		bool empty();
		//Returns true if the queue is empty and false otherwise.
		//Devuelve true si la cola está vacía y false en caso contrario.
		//
		size_t length();
		//Returns the amount of elements in the queue.
		//Devuelve la cantidad de elementos en la cola.
		//

		void enqueue(T data);
		//Adds an element data at the end of the queue.
		//Agrega un elemento data al final de la cola
		//
		T dequeue();
		//Pops the first element in the queue and returns it.
		//Saca de la cola el primer elemento y lo devuevle
		//

};




template <typename T>
Queue <T>::Queue(){
	_first = NULL;
	_last = NULL;
	_size = 0;
}

template <typename T>
Queue <T>::Queue(T data){
	_first = new NodeD<T>(data);
	_last = _first;
	_size = 1;
}

template <typename T>
T Queue <T>::first(){
	return _first->getData();
}

template <typename T>
T Queue <T>::last(){
	return _last->getData();
}

template <typename T>
bool Queue <T>::empty(){
	return _size == 0;
}

template <typename T>
size_t Queue <T>::length(){
	return _size;
}


template <typename T>
void Queue <T>::enqueue(T data){
	NodeD<T> *newNode = new NodeD<T>(data);

	if (empty()){
		_first = newNode;
	}
	else{
		//The previous and next pointers of last two nodes must be set because
		//every instance of double node initializes both to NULL.
		//
		//Hay que setear para el par de últimos nodos de la lista (el inicialmente último y el nuevo)
		//sus respectivos punteros a previo y siguiente, ya que se construyen inicialmente
		//apuntando a NULL.
		//
		_last->setPrev(newNode);
		newNode->setNext(_last);
	}

	_last = newNode;
	_size++;
}

template <typename T>
T Queue <T>::dequeue(){
	NodeD<T> *aux = _first;
	T data = aux->getData();
	_first = aux->getPrev();
	delete aux;
	_size--;
	return data;
}

template <typename T>
Queue <T> ::~Queue(){
	while (!empty())
		dequeue();
}

#endif //QUEUE_H
