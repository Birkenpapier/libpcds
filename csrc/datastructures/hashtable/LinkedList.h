#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList& ls);
	~LinkedList();

	LinkedList& operator=(const LinkedList&);

	bool insert(const std::string&);
	bool remove(const std::string&);
	bool search(const std::string&) const;

	std::vector<std::string> get() const;

private:
	class Node
	{
	public:
		std::string s_data;
		Node* n_next;
		Node(std::string s): s_data(s), n_next(NULL) {};
		Node(std::string s, Node* nd): s_data(s), n_next(nd) {};
	};

	Node* n_front;

	void deepCopy(const LinkedList& ls);
	void deleteList();
};
