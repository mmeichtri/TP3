#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include "queue.h"
#include <string>


using namespace std;

template <typename T>

class BinTreeNode{
private:
	T _data;
	string _key;
	BinTreeNode<T> *_left;
	BinTreeNode<T> *_right;
	BinTreeNode<T> *_prev;
public:
	BinTreeNode();
	BinTreeNode(T data, string key);
	~BinTreeNode();
	//
	//Creates a new node with the key-value pair specified as parameters and
	//adds it to the right or left branch of the most inmediate leaf of the tree.
	//POST: adds a new pair key-value to a sub-tree according to the comparison
	//between the object's key and the key given as parameter.
	bool addBst(T _data, string key);
	//
	//PRE: The node exists.
	//POST: returns true if there is not any branch (right or left) from the node; false in opposite case.
	bool isLeaf();
	//
	//PRE: the node exists.
	//POST: returns the data saved in the node.
	T* getData();
	//
	//PRE: the node exists.
	//POST: returns the key of the node.
	string getKey();
	//
	//POST: returns the inmediate first left-branch node 
	BinTreeNode<T>* left();
	//
	//POST: returns the inmediate first right-branch node
	BinTreeNode<T>* right();
	//
	//POST: returns the previous node.
	BinTreeNode<T>* prev();
	//
	//PRE: the node exists.
	//POST: sets <data> as the new value saved in the node
	void setData(T data, bool del = false);
	//
	//PRE: the node exists.
	//POST: sets <key> as the new key saved in the node
	void setKey(string key);
	//
	//PRE: the node exists.
	//POST: sets <n> as the new right-branch sub-tree root.
	void setLeft(BinTreeNode *n);
	//
	//PRE: the node exists.
	//POST: sets <n> as the new left-branch sub-tree root.
	void setRight(BinTreeNode *n);
	//
	//PRE: the node exists.
	//POST: sets <n> as the previous node of this one.
	void setPrev(BinTreeNode *n);
	//
	//POST: enqueues in <list> all the values saved in the whole tree which
	//root is this node in a pre-order sort.
	void preOrder(Queue<T> *&list);
	//
	//POST: enqueues in <list> all the values saved in the whole tree which
	//root is this node sorted from smallest to largest.
	void inOrder(Queue<T> *&list);
	//
	//POST: enqueues in <list> all the values saved in the whole tree which
	//root is this node in a post-order sort.
	void postOrder(Queue<T> *&list);
	//
	//Post: returns a pointer to a node which its key matches <key> given as parameter.
	//If the key does not exists in the tree born from this node, it returns NULL pointer.
	BinTreeNode<T>* search(string key);
	//
	//POST: replaces this node with the first node found a the branch according to the side
	//("right" or "left") specified by <side> 
	void erasingFlip(string side);
	//
	//PRE: the previous node exists (prev() != NULL).
	//POST: replaces this by <node> from previous node link.
	void flipPrev(BinTreeNode<T> *node);
	//
	//POST: returns the node who saves the smallest value (according to its key)
	//found in the left branch or in this node if it is a leaf
	BinTreeNode<T>* findMin();
	//
	//POST: returns the node who saves the largest value (according to its key)
	//found in the right branch or in this node if it is a leaf
	BinTreeNode<T>* findMax();

};




template <typename T>
BinTreeNode <T>::BinTreeNode(){
	_key = "";
	_left = NULL;
	_right = NULL;
	_prev = NULL;
}


template <typename T>
BinTreeNode <T>::BinTreeNode(T data, string key){
	_data = data;
	_key = key;
	_left = NULL;
	_right = NULL;
	_prev = NULL;
}


template <typename T>
bool BinTreeNode <T>::addBst(T data, string key){ 
	if (key == this->_key)
		return false;

	else if (key < this->_key){
		if (_left != NULL)
			return _left->addBst(data, key);
		else{
			_left = new BinTreeNode(data, key);
			_left->_prev = this;
		}
	}
	else {
		if(_right != NULL)
			return _right->addBst(data, key);
		else{
			_right = new BinTreeNode(data, key);
			_right->_prev = this;
		}
	}
	return true;
}


template <typename T>
T* BinTreeNode <T>::getData(){
	return &_data;
}


template <typename T>
string BinTreeNode <T>::getKey(){
	return _key;
}


template <typename T>
BinTreeNode<T>* BinTreeNode <T>::left(){
	return _left;
}


template <typename T>
BinTreeNode<T>* BinTreeNode <T>::right(){
	return _right;
}


template <typename T>
BinTreeNode<T>* BinTreeNode <T>::prev(){
	return _prev;
}


template <typename T>
void BinTreeNode <T>::setData(T data, bool del){
	if (del)
		delete _data;
	_data = data;
}


template <typename T>
void BinTreeNode <T>::setKey(string key){
	_key = key;
}


template <typename T>
void BinTreeNode <T>::setLeft(BinTreeNode *n){
	_left = n;
}


template <typename T>
void BinTreeNode <T>::setRight(BinTreeNode *n){
	_right = n;
}


template <typename T>
void BinTreeNode <T>::setPrev(BinTreeNode *n){
	_prev = n;
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
BinTreeNode<T>* BinTreeNode <T>::search(string key){
	//
	//Compares this node's key with the argument of the method
	//If they match, it returns a pointer to this node's data
	if (this->_data == NULL)
		return NULL;
	if (this->_key == key)
		return this;
	//
	//If the key given as parameter does not match with the node's it looks for it
	//on one branch according to the result of comparison between them.
	else if (key < this->_key)
		return (_left == NULL ? NULL : _left->search(key));
	else
		return (_right == NULL ? NULL : _right->search(key));
}


template <typename T>
bool BinTreeNode <T>::isLeaf(){
	return _left == NULL && _right == NULL;
}


template <typename T>
void BinTreeNode <T>::erasingFlip(string side){
	if (side == "right"){
		this->_right->setPrev(this->_prev);
		flipPrev(this->_right);
	}
	else if (side == "left"){
		this->_left->setPrev(this->_prev);
		flipPrev(this->_left);
	}
	this->_left = NULL;
	this->_right = NULL;
	this->_prev = NULL;
}


template <typename T>
void BinTreeNode <T>::flipPrev(BinTreeNode<T> *node){
	if (_prev->_right == this)
		this->_prev->setRight(node);
	else if (_prev->_left == this)
		this->_prev->setLeft(node);
}

template <typename T>
BinTreeNode<T>* BinTreeNode <T>::findMin(){
	if(_left == NULL)
		return this;
	return _left->findMin();
}


template <typename T>
BinTreeNode<T>* BinTreeNode <T>::findMax(){
	if(_right == NULL)
		return this;
	return _right->findMin();
}


template <typename T>
BinTreeNode <T>::~BinTreeNode(){
	if (_left != NULL) delete _left;
	if (_right != NULL) delete _right;
	delete _data;
}


#endif //BINARY_TREE_NODE_H