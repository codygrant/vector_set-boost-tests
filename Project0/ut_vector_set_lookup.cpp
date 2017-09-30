/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on all lookup functions of the vector_set class
*/

#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

// 1. find()
BOOST_AUTO_TEST_CASE(lookup_find_tests) {

	vector_set<char> vs1{ 'y','r','u','a','c','m' };
	auto letter = vs1.find('c');
	BOOST_CHECK_EQUAL(*letter, 'c');					// dereference to get value

	// perform find() when value not in container
	auto letter1 = vs1.find(6);
	// verify iterator points to end() since value not found
	BOOST_CHECK_MESSAGE(letter1 == vs1.end(), "Iterator should be pointing to end()!");
}

// 2. lower_bound()
BOOST_AUTO_TEST_CASE(lookup_lower_bound_tests) {

	// lower_bound returns an iterator pointing to equivalent of value, or element after value
	vector_set<int> vs1{ 100,200,300,600,800 };
	auto num = vs1.lower_bound(300);
	// lower_bound() should point it to 300
	BOOST_CHECK_MESSAGE(*num == 300, "lower_bound() isn't working correctly! Should be pointing to 300 not " << *num);

	// perform lower_bound() when value not in container
	auto num1 = vs1.lower_bound(500);
	// lower_bound() should point it to 600
	BOOST_CHECK_MESSAGE(*num1 == 600, "Iterator should be pointing to 600 NOT " << *num1);
}