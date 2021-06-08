#ifndef List_Huffman_H
#define List_Huffman_H
class List_Hu
{
public:
	List_Hu();
	~List_Hu();
	void reset_list();
	void push_back(std::string key, char word,int count);
	void push_front(std::string key, char word, int count);
	void pop_back();
	void pop_front();
	unsigned int get_size();
	void print_to_console();
	void clear();
	bool isEmpty();
	std::string at_k(unsigned int index);
	int at_c(unsigned int index);
	char at_v(unsigned int index);
private:
	class List_HNode {
	public:
		std::string key;
		char word;
		int count;
		List_HNode* next;

		List_HNode(std::string key, char word,int count, List_HNode* next = nullptr)
		{
			this->count = count;
			this->word = word;
			this->key = key;
			this->next = next;
		};
		~List_HNode()
		{

		}

	};
	List_HNode* tail;
	List_HNode* head;
	unsigned int size;
};
#endif
