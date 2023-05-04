#include "LinkedList.h"

#define I_DEFAULT_ARR_SIZE 100

class HashTable
{
public:
	HashTable();
	HashTable(int);
	HashTable(const HashTable&);
	~HashTable();

	HashTable& operator=(const HashTable&);

	bool insert(const std::string&);
	bool remove(const std::string&);
	bool search(const std::string&) const;
	int size() const;
	int maxSize() const;
	double loadFactor() const;

	std::vector<std::string> intersection(const HashTable&) const;
	std::vector<std::string> unions(const HashTable&) const;
	std::vector<std::string> difference(const HashTable&) const;

private:
	LinkedList* ll_arr;

	int i_arr_size;
	int i_num_items;

	int hashFun(const std::string&) const;
	int getPrime(int) const;
	bool isPrime(int) const;
	void deepCopy(const HashTable& h);

	std::vector<std::string> get() const;
};
