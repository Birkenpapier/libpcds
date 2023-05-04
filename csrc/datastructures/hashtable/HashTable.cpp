#include "HashTable.h"

HashTable::HashTable()
{
	i_arr_size = I_DEFAULT_ARR_SIZE;
	ll_arr = new LinkedList[i_arr_size];
	i_num_items = 0;
}

HashTable::HashTable(int n)
{
	i_arr_size = getPrime(n);
	ll_arr = new LinkedList[i_arr_size];
	i_num_items = 0;
}

HashTable::HashTable(const HashTable& h)
{
	deepCopy(h);
}

HashTable::~HashTable()
{
	delete[] ll_arr;
}

HashTable& HashTable::operator=(const HashTable& h)
{
	if(this != &h)
	{
		if(h.ll_arr != NULL)
			delete[] ll_arr;

		deepCopy(h);
	}

	return *this;
}

bool HashTable::insert(const std::string& s)
{
	int i_hash = hashFun(s);
	bool b_success = ll_arr[i_hash].insert(s);
	i_num_items++;

	return b_success;
}

bool HashTable::remove(const std::string& s)
{
	int i_hash = hashFun(s);
	bool b_success = ll_arr[i_hash].remove(s);
	i_num_items--;

	return b_success;
}

bool HashTable::search(const std::string& s) const
{
	int i_hash = hashFun(s);
	bool b_found = ll_arr[i_hash].search(s);

	return b_found;
}

int HashTable::size() const
{
	return i_num_items;
}

int HashTable::maxSize() const
{
	return i_arr_size;
}

double HashTable::loadFactor() const
{
	return (i_num_items * 1.0) / i_arr_size;
}

std::vector<std::string> HashTable::intersection(const HashTable& h) const
{
	std::vector<std::string> vs_return;
	std::vector<std::string> vs_v = this->get();

	for(int i = 0; i < vs_v.size(); i++)
		if(h.search(vs_v[i]))
			vs_return.push_back(vs_v[i]);

	return vs_return;
}

std::vector<std::string> HashTable::unions(const HashTable& h) const
{
	std::vector<std::string> vs_return;
	std::vector<std::string> vs_v_first=this->get();
	std::vector<std::string> vs_v_second=h.get();

	for(int i=0;i<vs_v_second.size();i++)
		vs_return.push_back(vs_v_second[i]);

	for(int i=0;i<vs_v_first.size();i++)
		if(!h.search(vs_v_first[i]))
			vs_return.push_back(vs_v_first[i]);

	return vs_return;
}

std::vector<std::string> HashTable::difference(const HashTable& h) const
{
	std::vector<std::string> vs_return;
    std::vector<std::string> vs_v_first=this->get();
    std::vector<std::string> vs_v_second=h.get();
    
	for(int i = 0; i < vs_v_first.size(); i++)
        if(!h.search(vs_v_first[i]))
            vs_return.push_back(vs_v_first[i]);

    for(int i = 0; i < vs_v_second.size(); i++)
        if(!this->search(vs_v_second[i]))
            vs_return.push_back(vs_v_second[i]);
			
    return vs_return;
}

int HashTable::hashFun(const std::string& s) const
{
	int i_hash_val = 0;
	int i_ascii;
	int i_upper_bound = 96;
	int i_lower_bound = 64;
	int i_hash_mult = 32;

	for(int i = 0; i < s.size(); i++)
	{
		i_ascii = s[i] > i_upper_bound ? s[i] - i_upper_bound : s[i] - i_lower_bound;
		i_hash_val = (i_hash_val * i_hash_mult + i_ascii) % i_arr_size;
	}

	return i_hash_val;
}

int HashTable::getPrime(int n) const
{
	int i = 2 * n;

	while(!isPrime(i))
		i++;

	return i;
}

bool HashTable::isPrime(int n) const
{
	bool i_is_prime = true;

	for(int i_count = 2; i_count < n && i_is_prime; i_count++)
		if((n % i_count) == 0)
			i_is_prime = false;

	return i_is_prime;
}

void HashTable::deepCopy(const HashTable& h)
{
	if(h.ll_arr != NULL)
	{
		i_num_items = h.size();
		i_arr_size = h.maxSize();
		ll_arr = new LinkedList[i_arr_size];

		for(int i = 0; i < i_arr_size; i++)
			ll_arr[i] = h.ll_arr[i];
	}
}

std::vector<std::string> HashTable::get() const
{
	std::vector<std::string> vs_v, vs_tmp;

	for(int i = 0; i < maxSize(); i++)
	{
		vs_tmp = ll_arr[i].get();

		for(int j = 0; j < vs_tmp.size(); j++)
			vs_v.push_back(vs_tmp[j]);
	}

	return vs_v;
}
