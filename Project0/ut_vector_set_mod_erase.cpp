/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on the erase() modifier function of
				the vector_set class
*/

#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

// 1. Erase a single element
BOOST_AUTO_TEST_CASE(erase_single_test) {

	vector_set<int> vs1{ 5,9,23,43,76,563 };
	// create an iterator for erase()
	auto num = vs1.begin();
	vs1.erase(num);
	BOOST_CHECK_EQUAL(*vs1.begin(), 9);		// '5' should be erased and the elements shifted to the left 1 element
	BOOST_CHECK(*num == 9);					// num pointer should also be pointing to the new first element
	BOOST_CHECK(vs1.size() == 5);			// check to make sure size updated correctly
	// check last element
	auto last = vs1.end() - 1;
	BOOST_CHECK_EQUAL(*last, 563);
}

// 2. Erase a range of elements
BOOST_AUTO_TEST_CASE(erase_range_tests) {

	vector_set<int> vs1{ 5,9,23,43,76,563 };
	// create two iterators to make a range
	auto start_num = vs1.begin();
	auto end_num = start_num + 3;
	vs1.erase(start_num, end_num);

	// this should have erased 5,9,23...
	BOOST_CHECK_EQUAL(*vs1.begin(), 43);
	BOOST_CHECK(*start_num == 43);			// beginning element should be 43 now
	BOOST_CHECK(vs1.size() == 3);			// check to make sure size updated correctly
	// check last element
	auto last = vs1.end() - 1;
	BOOST_CHECK_EQUAL(*last, 563);
}