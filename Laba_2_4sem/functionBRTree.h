#include"List.h"
#include"NodeBRTree.h"
#include"stack.h"
#include <stdexcept>
#include<iostream>


void RBTree::create(queue* priority_queue) 
{
	while (priority_queue->get_size() > 1)
	{
		priority_queue->tree_construction();
		insertSort(priority_queue);
	}
	Root = priority_queue->head->date;
}

void RBTree::coding(Node* node,std::string& key) 
{
	if (node == nullptr) return;
	key += "0";
	coding(node->Lnext,key);
	node->key = key;
	key.erase(key.size() - 1);
	key += "1";
	coding(node->Rnext,key);
	key.erase(key.size() - 1);
	node->key = key;
}
void RBTree::Huffman(List_Hu * Huffman_table) 
{
	List<std::string>* List_keys=get_keys();
	List<char>* List_word=get_values();
	List<int>* List_count = get_count();
	for (unsigned int i = 0; i < List_keys->get_size(); i++) 
	{
		if(List_word->at(i)!='\0')
		Huffman_table->push_back(List_keys->at(i),List_word->at(i),List_count->at(i));
	}
}