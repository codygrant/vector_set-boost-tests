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

	// lower_bound returns an iterator pointing to first element in the
	// specified range
	vector_set<int> vs1{ 100,200,300,300,300,600,800,800 };
	auto num = vs1.lower_bound(300);
	BOOST_CHECK_EQUAL(*num, 300);
	// previous element should be '200'
	--num;
	BOOST_CHECK_MESSAGE(*num == 200, "lower_bound() isn't working correctly! Should be pointing to 200 not " << *num);
}