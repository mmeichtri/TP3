#ifndef BST_H
#define BST_H

#include <string>
#include "bin_tree_node.h"
#include "queue.h"

using namespace std;


template <typename T>

class Bst{
private:
	BinTreeNode<T> *_root;
	size_t _size;
	size_t _levels;

public:
	Bst();
	Bst(T data, string key);
	~Bst();

	void add(T data, string key);
	//Agrega <data> al árbol en caso de que no esté incluido previamente.
	//POST: agrega un dato nuevo e incrementa el tamaño.
	//
	T pop();
	/*EN CONSTRUCCIÓN*/
	//necesito crear un get() que devuelva un puntero al dato (o NULL si no existe)
	//y ahí eliminarlo del árbol, enlazando sus hijos con su padre de alguna forma adecuada.
	//
	//
	T get();

	bool empty();
	//PRE: el árbol existe.
	//POST: devuelve true si el arbol está vacío y false si no lo está.
	//
	size_t size();
	//PRE: el árbol existe.
	//POST: devuelve la cantidad de elementos que almacena.
	//
	size_t lvls();
	//
	//
	Queue<T>* preOrder();
	//POST: devuelve una cola con los elementos del árbol obtenidos
	//mediante un recorrido de pre-orden.
	//
	Queue<T>* inOrder();
	//POST: devuelve una cola con los elementos del árbol
	//ordenados de (primero) menor a mayor (último).
	//
	Queue<T>* postOrder();
	//POST: devuelve una cola con los elementos del árbol obtenidos
	//mediante un recorrido de prost-orden.
	//
	void showPreOrder();
	//POST: imprime los elementos del árbol ordenados según recorrido de pre-orden.
	//
	void showInOrder();
	//POST: imprime los elementos del árbol ordenados de menor a mayor.
	//
	void showPostOrder();
	//POST: imprime los elementos del árbol ordenados según recorrido de post-orden.
	//
	T* search(string key);
	//Busca una clave en el árbol y devuelve su valor.
	//POST: si existe la clave, devuelve un PUNTERO al valor correspondiente.
	//(OJO: si el tipo de dato a guardar es puntero a algo, devuelve un doble puntero).
	//
};



template <typename T>
Bst <T>::Bst(){
	_root = NULL;
	_size = 0;
	_levels = 0;
}


template <typename T>
Bst <T>::Bst(T data, string key){
	_root = new BinTreeNode<T>(data, key);
	_size = 1;
	_levels = 1;
}



template <typename T>
bool Bst<T> ::empty(){
	return _size == 0 || _root == NULL;
}


template <typename T>
void Bst <T>::add(T data, string key){
	if(empty()){
		_root = new BinTreeNode<T>(data, key);
		_size = 1;
		_levels = 1;
	}
	else if (_root->addBst(data, key))
		_size++;
}


template <typename T>
size_t Bst <T>::size(){
	return _size;
}


template <typename T>
size_t Bst <T>::lvls(){
	return _levels;
}


template <typename T>
Queue<T>* Bst <T>::preOrder(){
	if (empty())
		return NULL;

	Queue<T> *preList = new Queue<T>;
	_root->preOrder(preList);

	return preList;
}


template <typename T>
Queue<T>* Bst <T>::inOrder(){
	if (empty())
		return NULL;

	Queue<T> *inList = new Queue<T>;
	_root->inOrder(inList);

	return inList;
}

template <typename T>
Queue<T>* Bst <T>::postOrder(){
	if (empty())
		return NULL;

	Queue<T> *posList = new Queue<T>;
	_root->postOrder(posList);

	return posList;
}


template <typename T>
void Bst <T>::showPreOrder(){
	Queue<T> * list = this->preOrder();
	if (list == NULL){
		cout << "The tree is empty." << endl;
	}
	else{
		cout << "Elements in the tree in pre-order scanning:\n < ";
		for (size_t i = 0; i < this->_size; i++)
			cout << list->dequeue() << (i != this->_size - 1 ? ", " : " >");
		cout << endl;
		delete list;
	}
}


template <typename T>
void Bst <T>::showInOrder(){
	Queue<T> * list = this->inOrder();
	if (list == NULL){
		cout << "The tree is empty." << endl;
	}
	else{
		cout << "Elements in the tree in order scanning:\n < ";
		for (size_t i = 0; i < this->_size; i++)
			cout << list->dequeue() << (i != this->_size - 1 ? ", " : " >");
		cout << endl;
		delete list;
	}
}

template <typename T>
void Bst <T>::showPostOrder(){
	Queue<T> * list = this->postOrder();
	if (list == NULL){
		cout << "The tree is empty." << endl;
	}
	else{
		cout << "Elements in the tree in post-order scanning:\n < ";
		for (size_t i = 0; i < this->_size; i++)
			cout << list->dequeue() << (i != this->_size - 1 ? ", " : " >");
		cout << endl;
		delete list;
	}
}


template <typename T>
T* Bst <T>::search(string key){
	//
	//Primero chequeo que el árbol no esté vacío.
	//Si lo está, devuelvo NULL; si no, ejecuto el método de búsqueda
	//correspondiente a la clase nodo y devuelvo lo que retorne.
	if (empty())
		return NULL;
	return _root->search(key);
}


template <typename T>
Bst <T> ::~Bst(){
	delete _root;
}



#endif //BST_H
