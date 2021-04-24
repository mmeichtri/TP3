#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

#include "node.h"


template <typename T>

class NodeD : public Node<T>{
private:
	NodeD<T> *_prev;

public:
	NodeD(T data);
	//Builds a double linked node, with both previous and next attributes pointint to NULL.
	//Construye un nodo doble, con ambos enlaces apuntando inicialmente a NULL.
	//
	void setPrev(NodeD<T> *prev);
	//Points the previous node to the node <prev> passed as parameter.
	//Apunta retrospectivamente el nodo al nodo <prev> pasado por parámetro.
	//
	NodeD<T> *getPrev();
	//Returns a pointer to the previous node.
	//Devuelve un puntero al nodo anterior.
	//
	~NodeD();
};



template <typename T>
NodeD<T> ::NodeD(T data) : Node <T>(data) {_prev = NULL;}

template <typename T>
void NodeD<T> ::setPrev(NodeD<T> *prev){
	_prev = prev;
}

template <typename T>
NodeD<T> *NodeD<T> ::getPrev(){
	return _prev;
}

template <typename T>
NodeD<T>::~NodeD(){

}



#endif	//DOUBLE_NODE_H
