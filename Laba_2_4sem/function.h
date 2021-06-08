#include"queue.h"
#include"RBTree.h"
#include<iostream>

void insertSort(queue* priority_queue) 
{
	int j;
	for (unsigned int i = 1; i < priority_queue->get_size(); i++) 
	{
		j = i - 1;
		unsigned int c = priority_queue->at_c(i);
		char w = priority_queue->at_w(i);
		Node* n = new Node();
		n = priority_queue->at_n(i);
		while (j >= 0 && priority_queue->at_c(j) > c) 
		{
			priority_queue->add_c(j + 1, priority_queue->at_w(j), priority_queue->at_c(j),priority_queue->at_n(j));
			j--;
		}
		priority_queue->add_c(j + 1,w, c,n);
	}
}

void count(std::string sentence, queue* priority_queue) 
{
	for (unsigned int i = 0; i < sentence.size(); i++) 
	{
		if (priority_queue->get_size() == 0) 
		{
			priority_queue->push(sentence[i]);
		}
		else
		{
			bool flag = true;
			for (unsigned int j = 0; j < priority_queue->get_size(); j++) 
			{
				if (priority_queue->at_w(j) == sentence[i]) 
				{
					priority_queue->add_at(j);
					flag = false;
					break;
				}
			}
			if (flag) 
			{
				priority_queue->push(sentence[i]);
			}
		}
	}
	insertSort(priority_queue);
}
void queue::tree_construction() 
{
	Node* tree =new Node;
	tree->Lnext = new Node;
	tree->Rnext = new Node;
	if (head->date == NULL)
		tree->push_left(tree,at_w(0), head->count);
	else {
		tree->Lnext = head->date;
		head->date->parent = tree->Lnext;
	}
	if (head->next->date == NULL)
		tree->push_right(tree, at_w(1), head->next->count);
	else {
		tree->Rnext = head->next->date;
		head->next->date->parent = tree->Rnext;
	}
	head->next->date = tree;
	head->next->count += head->count;
		pop();
}
std::string string_encoding(std::string sentence,List_Hu* list) 
{
	std::string string_enc = "";
	for (int i = 0; i < sentence.size(); i++) 
	{
		for (int j = 0; j < list->get_size(); j++) 
		{
			if (sentence[i] == list->at_v(j)) 
			{
				string_enc += list->at_k(j);
				break;
			}
		}
	}
	std::cout << "Закодированное предложение: " << string_enc<<"\n"<< "\n";
	return string_enc;
}
std::string string_decoding(std::string sentence, RBTree* tree) 
{
	std::string string_dec = "";
	Node* cur = new Node;
	cur = tree->Root;
	for (int i = 0; i < sentence.size(); i++) 
	{
		if (sentence[i] == '0') {
			cur = cur->Lnext;
			if(cur->Lnext==nullptr&& cur->Rnext == nullptr)
			{
				string_dec += cur->word;
				cur = tree->Root;
			}
		}
		if (sentence[i] == '1') 
		{
			cur = cur->Rnext;
			if (cur->Lnext == nullptr && cur->Rnext == nullptr) 
			{
				string_dec += cur->word;
				cur = tree->Root;
			}
		}
	}
	std::cout << "Декодированное предложение: " << string_dec << "\n" << "\n";
	return string_dec;
}
void Result(RBTree* tree,List_Hu* List,std::string sentence) 
{
	List->print_to_console();
	std::string string_enc = string_encoding(sentence, List);
	std::string string_dec = string_decoding(string_enc, tree);
	float n1 = sentence.size() * 8, n2 = string_enc.size();
	std::cout <<"Объем памяти исходной строки: "<<n1<<"\n";
	std::cout <<"Объем памяти закодированной строка: "<< n2<<"\n";
	std::cout <<"Коэффициент сжатия: "<<(1-(n2/n1) )*100<<"%"<<"\n";

}
