#include "node.h"

Node::Node(Key_data key, Data value){
	this->key = key;
	this->value = value;
	this->right = 0;
	this->left = 0;
}

Key_data Node::get_key(){
	return key;
}

void Node::set_key(Key_data key){
	this->key = key;
}

Data Node::get_data(){
	return value;
}

void Node::set_data(Data value){
	this->value = value;
}
