#ifndef Node_H
#define Node_H

typedef int Key_data; //made a different type of data for the key so is more general
typedef int Data;

class Node{
private:
	Key_data key;
	Data value;
public:
	Node* right;
	Node* left;
	Node(Key_data key, Data value);
	Key_data get_key();
	void set_key(Key_data key);
	Data get_data();
	void set_data(Data value);
};

#endif
