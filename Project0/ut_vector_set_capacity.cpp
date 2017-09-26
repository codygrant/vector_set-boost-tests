/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on all capacity functions of the vector_set class
*/

#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_CASE(capacity_tests) {

	// 1. Empty
	vector_set<size_t> vs1;
	BOOST_CHECK(vs1.empty());
	vector_set<unsigned char> vs2{ 'a','z','t' };
	BOOST_CHECK(!vs2.empty());

	// 2. Size
	BOOST_CHECK_EQUAL(vs1.size(), 0);
	BOOST_CHECK_EQUAL(vs2.size(), 3);

	// 3. Capacity
	BOOST_CHECK_EQUAL(vs1.capacity(), 0);	// an un-initialized STL container should have cap = 0	
}