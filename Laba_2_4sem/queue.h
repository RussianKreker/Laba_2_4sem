#ifndef queue_H
#define queue_H
#include"NodeBRTree.h"
class queue
{
private:
	class queueNode 
	{
	public:
		Node* date;
		queueNode* next;
		char word{};
		unsigned int count{};
		queueNode(Node*date = nullptr, queueNode* next = nullptr)
		{
			this->date = date;
			this->next = next;
		};
		queueNode(char word, unsigned int count= 1, Node* date = nullptr, queueNode* next = nullptr)
		{
			this->word = word;
			this->count = count;
			this->date = date;
			this->next = next;
		};
		~queueNode()
		{

		}

	};
public:
	queueNode* head;
	queueNode* tail;
	unsigned int size;
	queue()
	{
		tail = nullptr;
		head = nullptr;
		size = 0;
	}
	~queue() 
	{
		clear();
	}
	unsigned int get_size() 
	{
		return size;
	}
	void clear() 
	{
		while (size != 0)
		{
			pop();
		}
	}
	void push(char word) 
	{
		if (size == 0) 
		{
			head = new queueNode(word);
			tail = head;
		}
		else {
			tail->next = new queueNode(word);
			tail = tail->next;
		}
		size++;
	}
	void push(char word,unsigned int count) 
	{
		if (size == 0) 
		{
			head = new queueNode(word,count);
			tail = head;
		}
		else {
			tail->next = new queueNode(word, count);
			tail = tail->next;
		}
		size++;
	}

	void pop() 
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
			queueNode* current = head;
			head = head->next;
			delete current;
		}
		size--;
	}
	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}
	char at_w(unsigned int index)
	{
		if (index >= size) 
		{
			throw std::out_of_range("Index is greater than list size");
		}
		else {
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) 
			{
				current = current->next;
				counter++;
			}
			return current->word;
		}
	}
	queueNode* at_q(unsigned int index)
	{
		if (index >= size) 
		{
			throw std::out_of_range("Index is greater than list size");
		}
		else {
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) 
			{
				current = current->next;
				counter++;
			}
			return current;
		}
	}
	unsigned int at_c(unsigned int index)
	{
		if (index >= size) 
		{
			throw std::out_of_range("Index is greater than list size");
		}
		else {
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) 
			{
				current = current->next;
				counter++;
			}
			return current->count;
		}
	}
	Node* at_n(unsigned int index)
	{
		if (index >= size)
		{
			throw std::out_of_range("Index is greater than list size");
		}
		else {
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) 
			{
				current = current->next;
				counter++;
			}
			return current->date;
		}
	}
	void add_at(unsigned int index)
	{
		if (index >= size) 
		{
			throw std::out_of_range("Index is greater than list size");
		}
		else 
		{
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) 
			{
				current = current->next;
				counter++;
			}
			current->count++;
		}
	}
	void add_c(unsigned int index,char w,unsigned int c, Node* n) 
	{
		if (index >= size) 
		{
			throw std::out_of_range("Index is greater than list size");
		}
		else 
		{
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) 
			{
				current = current->next;
				counter++;
			}
			current->count = c;
			current->word = w;
			current->date = n;
		}
	}
	void tree_construction();
};
#endif
