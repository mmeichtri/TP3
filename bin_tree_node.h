#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include "queue.h"

using namespace std;

template <typename T>

class BinTreeNode{
private:
	T _data;
	BinTreeNode<T> *_left;
	BinTreeNode<T> *_right;
	BinTreeNode<T> *_prev;

public:
	BinTreeNode(T data);
	~BinTreeNode();
	T getData();
	bool addBst(T _data);
	void preOrder(Queue<T> *&list);
	void inOrder(Queue<T> *&list);
	void postOrder(Queue<T> *&list);
	T* search(T data);
	//PRE: el nodo existe.
	//POST: devuelve un puntero al dato si <data> coincide con el dato del nodo y NULL
	//si no se puede hallar a izquierda o derecha según la desigualdad.
	//
};



template <typename T>
BinTreeNode <T>::BinTreeNode(T data){
	_data = data;
	_left = NULL;
	_right = NULL;
	_prev = NULL;
}


template <typename T>
bool BinTreeNode <T>::addBst(T data){
	if (data == this->_data)
		return false;

	else if (data < this->_data){
		if (_left != NULL)
			return _left->addBst(data);
		else{
			_left = new BinTreeNode(data);
			_left->_prev = this;
		}
	}
	else {
		if(_right != NULL)
			return _right->addBst(data);
		else{
			_right = new BinTreeNode(data);
			_right->_prev = this;
		}
	}
	return true;
}


template <typename T>
T BinTreeNode <T>::getData(){
	return _data;
}


template <typename T>
void BinTreeNode <T>::preOrder(Queue<T> * &list){
	//
	//agrego el dato de la raíz  de cada subárbol (nodo) a la cola y repito,
	//primero en todo el subarbol izquierdo y luego sobre el derecho.
	list->enqueue(this->_data);
	if (_left != NULL) _left->preOrder(list);
	if (_right != NULL) _right->preOrder(list);
}


template <typename T>
void BinTreeNode <T>::inOrder(Queue<T> *&list){
	//
	//llamo recursivamente a lo largo de todo el subárbol izquierdo hasta
	//llegar al elemento más chico del conjunto.
	if (_left != NULL) _left->inOrder(list);
	//
	//agrego el dato del nodo a la cola
	list->enqueue(this->_data);
	//
	//repito el procedimiento pero a lo largo de todo el subárbol derecho hasta
	//llegar al elemento más grande del conjunto.
	if (_right != NULL) _right->inOrder(list);
}


template <typename T>
void BinTreeNode <T>::postOrder(Queue<T> *&list){
	//
	//Recorre todo el subárbol izquierdo y luego el derecho de cada subárbol.
	//Una vez llegado a una hoja izquierda, guarda el dato en la cola,
	//repite el procedimiento con el subárbol derecho hasta llegar a una hoja derecha,
	//guarda su dato y luego guarda el dato de la raíz de cada subárbol hasta volver
	//a la raíz de todo el árbol, la cual agrega al final de la cola.
	if (_left != NULL) _left->postOrder(list);
	if (_right != NULL) _right->postOrder(list);
	list->enqueue(this->_data);
}


template <typename T>
T* BinTreeNode <T>::search(T data){
	//
	//Comparo el dato de mi nodo con el dato a buscar
	//Si coinciden, devuelvo un puntero al dato 
	//OJO: si el dato ya es de tipo puntero lo que devuelve es un puntero doble
	if (this->_data == data)
		return &_data;

	else if (data < this->_data)
		//
		//En caso de no coincidir y el dato a buscar ser menor,
		//chequeo que haya un subárbol izquierdo; si no existe devuelvo NULL
		//si existe, vuelvo a aplicar el algoritmo sobre el subárbol izquierdo
		return (_left == NULL ? NULL : _left->search(data));
	else
		//
		//mismo que en el caso anterior pero para el árbol derecho
		//en caso de que el valor a buscar sea mayor que el del nodo
		return (_right == NULL ? NULL : _right->search(data));
}


template <typename T>
BinTreeNode <T>::~BinTreeNode(){
	if (_left != NULL) delete _left;
	if (_right != NULL) delete _right;
}

#endif //BINARY_TREE_NODE_H
