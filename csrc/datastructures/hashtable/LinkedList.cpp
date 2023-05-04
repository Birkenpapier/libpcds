#include "LinkedList.h"

LinkedList::LinkedList()
{
	n_front = NULL;
}

LinkedList::LinkedList(const LinkedList& ls)
{
	deepCopy(ls);
}

LinkedList::~LinkedList()
{
	deleteList();
}

LinkedList& LinkedList::operator=(const LinkedList& ls)
{
	if(this != &ls)
	{
		deleteList();
		deepCopy(ls);
	}

	return *this;
}

bool LinkedList::insert(const std::string& s)
{
	if(search(s))
		return false;

	n_front = new Node(s, n_front);

	return true;
}

bool LinkedList::remove(const std::string& s)
{
	Node* n_tmp = n_front;

	if(n_tmp == NULL)
		return false;

	if(n_tmp->s_data == s)
	{
		n_front = n_tmp->n_next;

		delete n_tmp;

		return true;
	}
	else
	{
		while(n_tmp->n_next != NULL){
			if(n_tmp->n_next->s_data == s)
			{
				Node* deletedNode = n_tmp->n_next;
				n_tmp->n_next = n_tmp->n_next->n_next;

				delete deletedNode;

				return true;
			}

			n_tmp = n_tmp->n_next;
		}

		return false;
	}
}

bool LinkedList::search(const std::string& s) const
{
	Node* n_tmp = n_front;

	while(n_tmp != NULL)
	{
		if(n_tmp->s_data == s)
			return true;

		n_tmp = n_tmp->n_next;
	}

	return false;
}

std::vector<std::string> LinkedList::get() const
{
	std::vector<std::string> s_vect;

	for(Node* n_tmp = n_front; n_tmp != NULL; n_tmp = n_tmp->n_next)
		s_vect.push_back(n_tmp->s_data);

	return s_vect;
}

void LinkedList::deepCopy(const LinkedList& ls)
{
	n_front = NULL;

	if(ls.n_front != NULL)
	{
		Node* n_orig = ls.n_front;
		Node* n_cpy;

		n_cpy = new Node(n_orig->s_data, NULL);
		n_front = n_cpy;
		n_orig = n_orig->n_next;

		while(n_orig != NULL)
		{
			n_cpy->n_next = new Node(n_orig->s_data, NULL);
			n_cpy = n_cpy->n_next;
			n_orig = n_orig->n_next;
		}
	}
}

void LinkedList::deleteList()
{
	Node* n_tmp;

	while(n_front != NULL){
		n_tmp = n_front->n_next;

		delete n_front;

		n_front = n_tmp;
	}
}
