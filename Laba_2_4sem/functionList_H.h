#include"List_Huffman.h"
#include"NodeBRTree.h"
#include<iostream>

List_Hu::List_Hu()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
 
List_Hu::~List_Hu()
{
	clear();
}
 
void List_Hu::reset_list()
{
	tail = nullptr;
	head = nullptr;
}
 
unsigned int List_Hu::get_size()
{
	return size;
}
 
void List_Hu::push_back(std::string key, char word,int count)
{
	if (size == 0) 
	{
		head = new List_HNode(key, word, count);
		tail = head;
	}
	else {
		tail->next = new List_HNode(key, word, count);
		tail = tail->next;
	}
	size++;
}
 
void List_Hu::push_front(std::string key, char word, int count)
{
	if (size == 0) 
	{
		head = new List_HNode(key, word, count);
		tail = head;
	}
	else 
	{
		head = new List_HNode(key, word, count,head);
	}
	size++;
}
 
void List_Hu::pop_back() 
{
	if (size == 0) return;
	if (size == 1) {
		delete head;
		reset_list();
	}
	else 
	{
		List_HNode* current = head;
		while (current->next != tail) 
		{
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}
 
void  List_Hu::pop_front() 
{
	if (size == 0) 
	{
		return;
	}
	if (size == 1) 
	{
		delete head;
		reset_list();
	}
	else {
		List_HNode* current = head;
		head = head->next;
		delete current;
	}
	size--;
}
 
void List_Hu::print_to_console() 
{
	std::cout << "Символ: " << "\t" << "Частота:" << "\t" << "Код:" << "\n";
	if (size == 0) 
	{
		return;
	}
	else 
	{
		unsigned int index = get_size();
		List_HNode* current = head;
		while (index != 0) 
		{
			std::cout<<" "<< current->word << "\t\t" << current->count << "\t\t" << current->key << "\n";
			current = current->next;
			index--;
		}
		std::cout << std::endl;
	}
}
 
void List_Hu::clear()
{
	while (size != 0)
	{
		pop_front();
	}
}
 
bool List_Hu::isEmpty() 
{
	if (size != 0) 
	{
		return 0;
	}
	return 1;
}
 
std::string List_Hu::at_k(unsigned int index)
{
	if (index >= size) 
	{
		throw std::out_of_range("Index is greater than list size");
	}
	else 
	{
		List_HNode* current = head;
		unsigned int counter = 0;
		while (counter != index) 
		{
			current = current->next;
			counter++;
		}
		return current->key;
	}
}
int List_Hu::at_c(unsigned int index)
{
	if (index >= size) 
	{
		throw std::out_of_range("Index is greater than list size");
	}
	else {
		List_HNode* current = head;
		unsigned int counter = 0;
		while (counter != index) 
		{
			current = current->next;
			counter++;
		}
		return current->count;
	}
}
char List_Hu::at_v(unsigned int index)
{
	if (index >= size) 
	{
		throw std::out_of_range("Index is greater than list size");
	}
	else 
	{
		List_HNode* current = head;
		unsigned int counter = 0;
		while (counter != index) 
		{
			current = current->next;
			counter++;
		}
		return current->word;
	}
}