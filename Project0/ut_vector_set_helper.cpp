/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on helper functions of the vector_set class
*/

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

#include "vector_set.hpp"
#include <iostream>

using num_char_types = boost::mpl::list<short, int, long, long long, char, double>;

// 1. test the non-member swap() function
BOOST_AUTO_TEST_CASE_TEMPLATE(inline_swap_helper_tests, T, num_char_types) {

	vector_set<T> vs1{ 1,2,3 };
	vector_set<T> vs2{ 4,5,6 };
	swap(vs1, vs2);					// calls the vector_set swap() non-member function
	BOOST_CHECK(*vs1.begin() == 4);
	BOOST_CHECK(*vs2.begin() == 1);
}

// 2. test the non-member begin() function
BOOST_AUTO_TEST_CASE_TEMPLATE(begin_helper_tests, T, num_char_types) {

	vector_set<T> vs1{ 1,2,3 };
	auto beg = begin(vs1);						// calls the vector_set begin() non-member function
	BOOST_CHECK(*vs1.begin() == *beg);
	BOOST_CHECK(*beg == 1);
}

// 3. test the non-member end() function
BOOST_AUTO_TEST_CASE_TEMPLATE(end_helper_tests, T, num_char_types) {

	vector_set<T> vs1{ 1,2,3 };
	auto end_it = end(vs1);						// calls the vector_set end() non-member function
	BOOST_CHECK(vs1.end() == end_it);			// verify pointers are pointing to same spot		
	BOOST_CHECK(*(end_it-1) == 3);				// verify iterator is at last element
}