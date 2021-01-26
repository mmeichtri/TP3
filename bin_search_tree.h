#ifndef BST
#define BST
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
	Bst(T data);
	~Bst();
	
	void add(T data);
	T pop(T data);
	bool empty();
	size_t size();
	size_t lvls();
	Queue<T>* preOrder();
	Queue<T>* inOrder();
	Queue<T>* postOrder();
	void showPreOrder();
	void showInOrder();
	void showPostOrder();
};



template <typename T>
Bst <T>::Bst(){
	_root = NULL;
	_size = 0;
	_levels = 0;
}


template <typename T>
Bst <T>::Bst(T data){
	_root = BinTreeNode<T>(data);
	_size = 1;
	_levels = 1;
}



template <typename T>
bool Bst<T> ::empty(){
	return _size == 0 || _root == NULL;
}


template <typename T>
void Bst <T>::add(T data){
	if(empty()){
		_root = new BinTreeNode<T>(data);
		_size = 1;
		_levels = 1;
	}
	else if (_root->addBst(data))
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
Bst <T> ::~Bst(){
	delete _root;
}



#endif //BST