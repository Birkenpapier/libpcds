#include "HashTable.h"

void tests()
{
	HashTable ht_default;
	assert(ht_default.maxSize() == 100);
	assert(ht_default.size() == 0);

	int i_param = 7;
	HashTable ht_one_param(i_param);
	assert(ht_one_param.maxSize() == 17);
	assert(ht_one_param.size() == 0);

	assert(ht_one_param.insert("test") == 1);
	assert(ht_one_param.insert("testtest") == 1);
	assert(ht_one_param.insert("testtesttest") == 1);
	assert(ht_one_param.insert("test") == 0);

	std::string s_search_1 = "test";
	std::string s_search_2 = "testtest";
	std::string s_search_3 = "testtesttest";
	std::string s_search_4 = "notinhash";
	
	assert(ht_one_param.search(s_search_1) == 1);
	assert(ht_one_param.search(s_search_2) == 1);
	assert(ht_one_param.search(s_search_3) == 1);
	assert(ht_one_param.search(s_search_4) == 0);

	HashTable ht_copy(ht_one_param);
	assert(ht_one_param.remove(s_search_1) == 1);
	assert(ht_one_param.remove(s_search_2) == 1);
	assert(ht_one_param.remove(s_search_3) == 1);
	assert(ht_one_param.remove(s_search_4) == 0);
	assert(ht_one_param.remove(s_search_1) == 0);
	
	HashTable ht_copy_one_param = ht_one_param;
	HashTable ht_copy_of_copy = ht_copy;

	std::vector<std::string> vs_inter = ht_copy_one_param.intersection(ht_copy_of_copy);

	for (int i = 0; i < vs_inter.size(); i++)
		std::cout << vs_inter[i] << std::endl;

	std::vector<std::string> vs_union = ht_copy_one_param.unions(ht_copy_of_copy);

	for (int i = 0; i < vs_union.size(); i++)
		std::cout << vs_union[i] << std::endl;

	std::vector<std::string> vs_difference = ht_copy_one_param.difference(ht_copy_of_copy);

	for (int i = 0; i < vs_difference.size(); i++)
		std::cout << vs_difference[i] << std::endl;

	std::cout << "hashtable is working correctly" << std::endl;
}

int main()
{
	tests();

	return 0;
}
