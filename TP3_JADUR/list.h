#ifndef LIST_H
#define LIST_H
#include <string>
#include "node.h"

using namespace std;

template <typename T>
class List{
protected:
	Node<T> *_first;
	Node<T> *_last;
	Node<T> *_current;
	size_t _size;

public:
	List();
	List(T data);
	~List();
	
	T getFirst();
	//Returns the first element in the list.
	//Devuelve el primer elemento de la lista.
	//
	T getLast();
	//Returns the last element in the list.
	//Devuelve el último elemento de la lista.
	//
	T getCurrent();
	//POST:
	//Returns the element pointed by the iterator.
	//Devuelve el elemento apuntado por el iterador.
	//
	T get(size_t index);
	//Devuelve el elemento guardado en la posición <index>.
	//En caso de <index> desbordar el número de elementos, recorre la lista de forma circular hasta coincidir con
	//un elemento válido.
	//
	Node<T>* next();
	//
	//
	//
	size_t length();
	//Returns the size of the list.
	//Devuelve la cantidad de elementos de la lista.
	//
	bool empty();
	//Returns true if the list is empty and fale otherwise. 
	//devuelve true si la lista está vacía (no contiene elementos), si no devuelve false
	//
	void reboot();
	//POST:
	//Links the iterator to the first element in the list.
	//
	void append(T data);
	//POST:
	//Adds an element data at the end of the list.
	//Agrega un elemento al final de la lista.
	//
	void popFirst();
	//PRE:
	//The list is not empty.
	//La lista no está vacía.
	//POST:
	//Pops and returns the first element in the list. 
	//saca el primer elemento de la lista y lo devuelve.
	//
	void popLast();
	//PRE:
	//The list is not empty.
	//La lista no está vacía.
	//
	//POST:
	//Pops and returns the last element in the list.
	//saca el último elemento de la lista y lo devuelve.
	//
	void remove();
	//PRE:
	//The iterator is not pointing to NULL.
	//El iterador debe apuntar a un elemento válido.
	//
	//POST:
	//Removes the element pointed by the iterator.
	//Elimina de la lista el elemento apuntado por el iterador.
	//
	T* search(string key, int (*compareObject)(const T, const void *));
	//POST:
	//If the key matches the searched element, being both compared with an appropiate method <compareObject>
	//returns a pointer to that element. Otherwise it returns NULL.
	//Compara la clave con el objeto a buscar usando una funcion que corresponda, y si coinciden devuelve
	//un puntero a dicho objeto. En caso de no coincidir devuelve un puntero nulo.
	//
	void clear();
	//POST:
	//Remove every element in the list.
	//Borra todos los elementos guardados en la lista.
	//

};



template <typename T>
List <T>::List(){
	_first = NULL;
	_last = NULL;
	_size = 0;
}


template <typename T>
List <T>::List(T data){
	_first = new Node<T>(data);
	_last = _first;
	_size = 1;
}


template <typename T>
T List <T>::getFirst(){
	return _first->getData();
}


template <typename T>
T List <T>::getLast(){
	return _last->getData();
}


template <typename T>
T List <T>::getCurrent(){
	return _current->getData();
}


template <typename T>
T List <T>::get(size_t index){
	if (index > _size){
		index %= _size;
		if (index == 0)
			index = _size;
	}
	else if (index == _size)
		return _last->getData();

	else if (index == 1 || index == 0)
		return _first->getData();


	size_t i = 1;
	_current = _first;
	while (i != index){
		_current = _current->getNext();
		i++;
	}
	return _current->getData();
}


template <typename T>
Node<T>* List <T>::next(){
	if(_current == NULL || this->empty())
		return NULL;

	return _current->getNext();
}


template <typename T>
size_t List <T>::length(){
	return _size;
}


template <typename T>
bool List <T>::empty(){
	return _size == 0 || _first == NULL;
}


template <typename T>
void List <T>::reboot(){
	_current = _first;
}


template <typename T>
void List <T>::append(T data){
	Node<T> *newNode = new Node<T>(data);
	
	if (_size == 0){
		_first = newNode;
	}
	else{
		_last->setNext(newNode);
	}
	_last = newNode;
	_size++;
	
}


template <typename T>
void List <T>::popFirst(){
	if (_first == NULL)
		return;
	Node<T> *aux = _first;
	_first = _first->getNext();
	delete aux;
	_size--;
}


template <typename T>
void List <T>::popLast(){
	if (empty())
		return;
	Node<T> *aux = _last;
	if (_current == _last)
		reboot();

	while(_current->getNext() != _last)	
		_current = _current->getNext();

	//current->next == _last
	_current->setNext(NULL);
	_last = _current;
	delete aux;
	_size--;
	
}


template <typename T>
void List <T>::remove(){
	if (!empty() && _current != NULL && _current != _first && _current != _last){
		Node<T> *aux = _first;

		while(aux->getNext() != _current)
			aux = aux->getNext();
		
		aux->setNext(_current->getNext());
		aux = _current;
		_current = _current->getNext();
		delete aux;
		_size--;
	}
	else if (_current == _first)
		popFirst();
	else if (_current == _last)
		popLast();
}


template <typename T>
T* List <T>::search(string key, int (*compareObject)(T, const void *b)){
	reboot();
	while (_current != NULL){
		if (compareObject(_current->getData(), &key) == 0){
			T data = (_current->getData());
			T *found = &data;
			return found;
		}
		_current = _current->getNext();
	}
	return NULL;
}


template <typename T>
void List <T>::clear(){
	while(!empty())
		popFirst();
	
	_first = NULL;
	_last = NULL;
}


template <typename T>
List <T>::~List(){
	while(!empty())
		popFirst();

}


#endif //LIST_H