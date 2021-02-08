#ifndef NODE_H
#define NODE_H

#include <cstddef>

//Nodo simple
template <typename T>

class Node{
protected:
	T _data;
	Node<T> *_next;

public:
	Node(T d);

	void setNext(Node *next);
	//Points the self point to the node <next>.
	//Hace apuntar al nodo que la llama al nodo recibido por parámetro.
	//
	T getData();
	//Returns the element saved in the node.
	//Deveuvle el elemento guardado en el nodo.
	//
	Node<T> *getNext();
	//Returns a pointer to te next node in the list.
	//Devuelve un puntero al nodo siguiente.
	//

	virtual ~Node();
};



//MÉTODOS NODO

template <typename T>
Node <T>::Node(T d){
	_data = d;
	_next = NULL;
}


template <typename T>
void Node <T>::setNext(Node<T> *next){
	_next = next;
}


template <typename T>
T Node <T>::getData(){
	return _data;
}


template <typename T>
Node<T> * Node <T>::getNext(){
	return _next;
}


template <typename T>
Node<T>::~Node(){

}


#endif	//NODE_H
