#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

Dictionary::Dictionary(){
	root = 0;
}

//public insert method
void Dictionary::insert(Key_data key, Data value){
	root = insert(this->root, key, value); //calls the private insert method
}

//private insert method
Node* Dictionary::insert(Node* node, Key_data key, Data value){
	if(node == 0){ //case empty dictionary
		node = new Node(key, value);
  }
  else if(key <= node->get_key()){
    node->left = insert(node->left, key, value); //goes left -> recursive call in the left branch
  }
	else{
		node->right = insert(node->right, key, value); //goes right -> recursive call in the right branch
	}
	return node;
}

//public delete method
void Dictionary::erase(Key_data key){
	std::cout << '\n';
	Key_data original_key = key;
	root = erase(this->root, key, original_key);
}

//private delete method
Node* Dictionary::erase(Node* node, Key_data key, Key_data original_key){
	if(node == 0) //case empty dictionary
		return node;
	//goes left
  else if(key < node->get_key())
    node->left = erase(node->left, key, original_key);
	//goes right
	else if(key > node->get_key())
		node->right = erase(node->right, key, original_key);

	//found the node with the key
	else
	{
		//case node with no childs
		if(node->left == 0 && node->right == 0){
			delete node;
			node = 0;
			std::cout << "Node with key: " << original_key << " erased from the dictionary." << '\n';
		}

		//case node has ONE child
		else if(node->left == 0){
			Node* aux = node;
			node = node->right;
			delete aux;
			std::cout << "Node with key: " << original_key << " erased from the dictionary." << '\n';
		}

		else if(node->right == 0){
			Node* aux = node;
			node = node->left;
			delete aux;
			std::cout << "Node with key: " << original_key << " erased from the dictionary." << '\n';
		}

		//case node has 2 childrens
		else{
			Node* node_to_replace = find_min(node->right); //change name of this variable
			node->set_key(node_to_replace->get_key());
			node->set_data(node_to_replace->get_data());
			node->right = erase(node->right, node->get_key(), original_key);
		}
	}
	return node;
}

void Dictionary::search(Key_data key){
	Node* wanted_node = search(this->root, key);
	if(wanted_node != 0)
		std::cout << "Key: " << key << " found" << '\n';
	else
		std::cout << "ERROR: Key: '" << key << "' not found" << '\n';
}

void Dictionary::get(Key_data key){
	Node* wanted_node = search(this->root, key);
	if(wanted_node != 0)
		std::cout << "Key: " << wanted_node->get_key() << ", Value: " << wanted_node->get_data() << '\n';
	else
		std::cout << "ERROR: Key: '" << key << "' not found" << '\n';
}

void Dictionary::modify(Key_data key, Data new_data){
	Node* node_to_modify = search(this->root, key);
	if(node_to_modify != 0){
		node_to_modify->set_data(new_data);
		std::cout << "Key: " << node_to_modify->get_key() << ", Value: " << node_to_modify->get_data() << '\n';
	}
	else
		std::cout << "ERROR: Key: '" << key << "' not found" << '\n';
}

Node* Dictionary::search(Node* node, Key_data key){
	if(node == 0)
		return node;
	else if(node->get_key() == key)
	 	return node;
	else if(key < node->get_key())
		return search(node->left, key);
	else
		return search(node->right, key);
}

//needs to return key and value
void Dictionary::find_min(){
	if(this->root == 0){
		std::cout << "dictionary is empty" << '\n';
		return;
	}
	Node* min_node = find_min(this->root);
	std::cout << "The node with the minimun key is: " << min_node->get_key() << "value: "<< min_node->get_data() << '\n';
}

Node* Dictionary::find_min(Node* node){
	if(node->left == 0)
		return node;
	return find_min(node->left);
}

void Dictionary::find_max(){
	if(this->root == 0){
		std::cout << "dictionary is empty" << '\n';
		return;
	}
	Node* max_node = find_min(this->root);
	std::cout << "The node with the maximun key is: " << max_node->get_key() << "value: "<< max_node->get_data() << '\n';
}

Node* Dictionary::find_max(Node* node){
	if(node->right == 0)
		return node;
	return find_max(node->right);
}

int Dictionary::get_dictionary_height(){
	return get_dictionary_height(this->root);
}

int Dictionary::get_dictionary_height(Node* node){
	if(node == 0)
		return -1;
	return max(get_dictionary_height(node->left), get_dictionary_height(node->right)) + 1;
}

void Dictionary::travel_dictionary(){
	travel_dictionary(this->root);
}

void Dictionary::travel_dictionary(Node* node){
	if(node == 0) return;
	travel_dictionary(node->left);
	std::cout << node->get_key() << ": " << node->get_data() << '\n';
	travel_dictionary(node->right);
}

Dictionary::~Dictionary(){
	erase_dictionary(this->root);
}

Node* Dictionary::erase_dictionary(Node* node){
	if(node->left != 0)
		node->left = erase_dictionary(node->left);

	if(node->right != 0)
		node->right = erase_dictionary(node->right);

	if(node->left == 0 && node->right == 0){
		delete node;
		return node = 0;
	}
}
