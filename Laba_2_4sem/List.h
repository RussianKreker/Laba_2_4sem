#ifndef List_H
#define List_H
#include"NodeBRTree.h"
template <typename Data>
class List
{
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	~List()
	{
		clear();
	}

	void reset_list()
	{
		tail = nullptr;
		head = nullptr;
	}

	void push_back(Data date)
	{
		if (size == 0) {
			head = new ListNode(date);
			tail = head;
		}
		else {
			tail->next = new ListNode(date);
			tail = tail->next;
		}
		size++;
	}

	void push_front(Data date)
	{
		if (size == 0) {
			head = new ListNode(date);
			tail = head;
		}
		else {
			head = new ListNode(date, head);
		}
		size++;
	}

	void pop_back() 
	{
		if (size == 0) return;
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			Node* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			current->next = nullptr;
			delete tail;
			tail = current;
		}
		size--;
	}

	void pop_front() 
	{
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			ListNode* current = head;
			head = head->next;
			delete current;
		}
		size--;
	}

	unsigned int get_size()
	{
		return size;
	}

	void print_to_console()
	{
		if (size == 0) {
			return;
		}
		else {
			unsigned int index = get_size();
			ListNode* current = head;
			while (index != 0) {
				std::cout << current->value << " ";
				current = current->next;
				index--;
			}
			std::cout << std::endl;
		}
	}

	void clear()
	{
		while (size != 0)
		{
			pop_front();
		}
	}

	bool isEmpty()
	{
		if (size != 0) {
			return 0;
		}
		return 1;
	}

	Data at(unsigned int index)
	{
		if (index >= size) {
			throw std::out_of_range("Index is greater than list size");
		}
		else {
			ListNode* current = head;
			unsigned int counter = 0;
			while (counter != index) {
				current = current->next;
				counter++;
			}
			return current->data;
		}
	}

private:
	class ListNode {
	public:
		Data data;
		ListNode* next;

		ListNode(Data data, ListNode* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~ListNode()
		{

		}

	};
	ListNode* tail;
	ListNode* head;
	unsigned int size;
};
#endif
