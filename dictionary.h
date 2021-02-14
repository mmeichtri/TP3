#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "node.h"

typedef int Data;

class Dictionary{
private:
	Node* root;
	Node* insert(Node* root, Key_data key, Data value);
	Node* erase(Node* root, Key_data key, Key_data original_key);

	Node* search(Node* node, Key_data key);

	Node* find_min(Node* node);
	Node* find_max(Node* node);

	int get_dictionary_height(Node* node);

	void travel_dictionary(Node* node);

	Node* erase_dictionary(Node* node);

public:
	Dictionary();
	~Dictionary();
	void insert(Key_data key, Data value);
	void erase(Key_data key);
	void modify(Key_data key, Data new_data);

	void search(Key_data key);
	void get(Key_data key);

	void find_min();
	void find_max();

	int get_dictionary_height();

	void travel_dictionary();

};

#endif
