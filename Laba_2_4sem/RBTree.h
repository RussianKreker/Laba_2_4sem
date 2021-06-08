#ifndef RBTree_H
#define RBTree_H
#include"NodeBRTree.h"
#include"stack.h"
#include"List.h"
#include"List_Huffman.h"
#include"queue.h"

class RBTree
{
public:
	RBTree()
	{
		Root = NULL;
	}

	~RBTree()
	{
		clear();
		Root = nullptr;
	}

	Node* Root;

	void clear()
	{
		preorder(Root);
		Root = nullptr;
	}

	void preorder(Node* node)
	{
		if (node == nullptr) return;
		preorder(node->Lnext);
		preorder(node->Rnext);
		delete node;
	}

	List<std::string>* get_keys()
	{
		if (Root == NULL) {
			throw("There is no element");
		}
		stack  stackKey;
		List<std::string>* listKey = new List<std::string>;
		stackKey.push(Root);
		bool flag = true;
		Node* temp = stackKey.head->date;
		while (!stackKey.isEmpty())
		{
			listKey->push_back(temp->key);
			if (temp->Rnext != NULL)
			{
				if (flag) {
					stackKey.pop_front();
					flag = false;
				}
				stackKey.push(temp->Rnext);
			}
			if (temp->Lnext != NULL)
			{
				temp = temp->Lnext;
			}
			else
			{

				if (flag) {
					stackKey.pop_front();
				}
				if (!stackKey.isEmpty())
				{
					temp = stackKey.head->date;
				}
				flag = true;
			}
		}
		return listKey;
	}

	List<char>* get_values()
	{
		if (Root == NULL)
		{
			throw("There is no element");
		}
		stack  stackValue;
		List<char>* listValue = new List<char>;
		stackValue.push(Root);
		bool flag = true;
		Node* temp = stackValue.head->date;
		while (!stackValue.isEmpty())
		{
			listValue->push_back(temp->word);
			if (temp->Rnext != NULL)
			{
				if (flag) {
					stackValue.pop_front();
					flag = false;
				}
				stackValue.push(temp->Rnext);
			}
			if (temp->Lnext != NULL)
			{
				temp = temp->Lnext;
			}
			else
			{

				if (flag)
				{
					stackValue.pop_front();
				}
				if (!stackValue.isEmpty())
				{
					temp = stackValue.head->date;
				}
				flag = true;
			}
		}
		return listValue;
	}

	List<int>* get_count()
	{
		if (Root == NULL)
		{
			throw("There is no element");
		}
		stack  stackValue;
		List<int>* listValue = new List<int>;
		stackValue.push(Root);
		bool flag = true;
		Node* temp = stackValue.head->date;
		while (!stackValue.isEmpty())
		{
			listValue->push_back(temp->count);
			if (temp->Rnext != NULL)
			{
				if (flag)
				{
					stackValue.pop_front();
					flag = false;
				}
				stackValue.push(temp->Rnext);
			}
			if (temp->Lnext != NULL)
			{
				temp = temp->Lnext;
			}
			else
			{

				if (flag)
				{
					stackValue.pop_front();
				}
				if (!stackValue.isEmpty())
				{
					temp = stackValue.head->date;
				}
				flag = true;
			}
		}
		return listValue;
	}

	void create(queue* priority_queue);

	void Huffman(List_Hu* Huffman_table);

	void coding(Node* node,std::string& key);

};
#endif