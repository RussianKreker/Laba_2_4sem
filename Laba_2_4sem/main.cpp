#include"function.h"
#include"RBTree.h"
#include"functionBRTree.h"
#include"List_Huffman.h"
#include"functionList_H.h"
#include"List.h"
#include<string>
#include <windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите предожение для кодирования: " << "\n";
	std::string sentence;
	std::getline(std::cin, sentence);
	std::string k="";
	std::string kk="";
	queue* ggg = new queue;
	RBTree* tree = new RBTree;
	List_Hu* List= new List_Hu;
	count(sentence, ggg);
	tree->create(ggg);
	tree->coding(tree->Root,k);
	tree->Huffman(List);
	Result(tree,List,sentence);
	return 13;
}