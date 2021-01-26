#ifndef BINARY_TREE_NODE
#define BINARY_TREE_NODE

#include "queue.h"

using namespace std;

template <typename T>

class BinTreeNode{
private:
	T _data;
	BinTreeNode *_left;
	BinTreeNode *_right;
	BinTreeNode *_prev;

public:
	BinTreeNode(T data);
	~BinTreeNode();
	T getData();
	bool addBst(T _data);
	void preOrder(Queue<T> *&list);
	void inOrder(Queue<T> *&list);
	void postOrder(Queue<T> *&list);
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
			return _left->add(data);
		else{
			_left = new BinTreeNode(data);
			_left->_prev = this;
		}
	}
	else {
		if(_right != NULL)
			return _right->add(data);
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
	list->enqueue(this->_data);
	if (_left != NULL) _left->preOrder(list);
	if (_right != NULL) _right->preOrder(list);
}


template <typename T>
void BinTreeNode <T>::inOrder(Queue<T> *&list){
	if (_left != NULL) _left->inOrder(list);
	list->enqueue(this->_data);
	if (_right != NULL) _right->inOrder(list);
}


template <typename T>
void BinTreeNode <T>::postOrder(Queue<T> *&list){
	if (_left != NULL) _left->postOrder(list);
	if (_right != NULL) _right->postOrder(list);
	list->enqueue(this->_data);
}


template <typename T>
BinTreeNode <T>::~BinTreeNode(){
	if (_left != NULL) delete _left;
	if (_right != NULL) delete _right;
}

#endif //BINARY_TREE_NODE