#ifndef NodeBRTree_H
#define NodeBRTree_H
#include<iostream>
class Node {
public:
	std::string key{};
	char word{};
	int count;
	Node* Lnext;
	Node* Rnext;
	Node* parent;
	Node(char word,int count, Node* parent = nullptr, Node* Lnext = nullptr, Node* Rnext = nullptr)
	{
		this->parent = parent;
		this->count = count;
		this->word = word;
		this->Lnext = Lnext;
		this->Rnext = Rnext;
	};
	Node(Node* parent = nullptr, Node* Lnext = nullptr, Node* Rnext = nullptr)
	{
		this->parent = parent;
		this->Lnext = Lnext;
		this->Rnext = Rnext;
	};
	~Node()
	{
		word = NULL;
		key= nullptr;
		Lnext = nullptr;
		Rnext = nullptr;
		parent = nullptr;

	}
	void push_left(Node* tree, char word,int count) {
		Node* left = new Node(word, count);
		tree->Lnext = left;
		left->parent = tree;
	}
	void push_right(Node* tree, char word,int count) {
		Node* right = new Node(word, count);
		tree->Rnext = right;
		right->parent = tree;
	}
};
#endif