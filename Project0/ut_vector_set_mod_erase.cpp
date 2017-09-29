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
	BOOST_CHECK(*num == 9);					// '5' should be erased and the elements shifted to the left 1 element
}