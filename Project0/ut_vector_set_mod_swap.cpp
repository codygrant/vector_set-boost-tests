/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on the swap() modifier function of
				the vector_set class
*/

#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

// 1. swap() size test
BOOST_AUTO_TEST_CASE(swap_size_test) {

	vector_set<int> vs1{ 1,2,3,4,5,6 };
	vector_set<int> vs2{ 7,8,9,10 };
	vs1.swap(vs2);
	BOOST_CHECK(vs1.size() == 4);		// 4 is size of vs2 before swap
	BOOST_CHECK(vs2.size() == 6);		// 6 is size of vs1 before swap

	vector_set<char> vs3{ 'y','r','u','e','7' };
	vector_set<char> vs4{ 'A','r','m','[' };
	vs3.swap(vs4);
	BOOST_CHECK(vs3.size() == 4);		// 4 is size of vs2 before swap
	BOOST_CHECK(vs4.size() == 5);		// 6 is size of vs1 before swap

	vector_set<string> vs5{ "cody","grant","london","boost" };
	vector_set<string> vs6{ "SCHOOL","fanshawe","programming" };
	vs5.swap(vs6);
	BOOST_CHECK(vs5.size() == 3);		// 4 is size of vs2 before swap
	BOOST_CHECK(vs6.size() == 4);		// 6 is size of vs1 before swap
}

// 2. swap() iterator test
BOOST_AUTO_TEST_CASE(swap_iterator_tests) {

	vector_set<int> vs1{ 1,2,3,4,5,6 };
	vector_set<int> vs2{ 7,8,9,10 };
	// grab the value of capacity iterators
	size_t vs1_original_cap = vs1.capacity();
	size_t vs2_original_cap = vs2.capacity();

	vs1.swap(vs2);
	BOOST_CHECK(*vs1.begin() == 7);							// check first element vs1
	BOOST_CHECK(*vs2.begin() == 1);							// check first element vs2
	BOOST_CHECK(*(vs1.end() - 1) == 10);					// check last element vs1
	BOOST_CHECK(*(vs2.end() - 1) == 6);						// check last element vs2
	BOOST_CHECK_EQUAL(vs1.capacity(), vs2_original_cap);	// compare capacities
	BOOST_CHECK_EQUAL(vs2.capacity(), vs1_original_cap);
}