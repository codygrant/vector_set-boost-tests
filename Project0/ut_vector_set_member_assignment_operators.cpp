/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on all member assignment operators
				of the vector_set class
*/

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

using num_char_types = boost::mpl::list<short, int, long, long long, double, char>;

BOOST_AUTO_TEST_CASE_TEMPLATE(copy_assignment_operator, T, num_char_types) {

	// fill one
	vector_set<T> vs1{ 1,2,3,4,5 };
	vector_set<T> vs2;
	vs2 = vs1;
	BOOST_CHECK_EQUAL(vs1.size(), vs2.size());
	BOOST_CHECK_EQUAL(*vs1.begin(), *vs2.begin());	// check that the values are the same
	BOOST_CHECK(!vs2.empty());

	// copy empty one into full one
	vector_set<T> vs3;
	vs2 = vs3;
	BOOST_CHECK(vs2.empty());
	BOOST_CHECK_EQUAL(vs2.size(), 0);
	BOOST_CHECK(vs3.empty());

	// copy different sized one
	vector_set<T> vs4{ 1,2,3,4,5,6,7 };
	vector_set<T> vs5{ 1,2,3,4,5 };
	size_t vs4_size = vs4.size();
	size_t vs5_original_size = vs5.size();
	vs5 = vs4;
	BOOST_CHECK_EQUAL(vs5.size(), vs4_size);
	BOOST_CHECK(vs5.size() != vs5_original_size);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(move_assignment_operator, T, num_char_types) {

	// fill one
	vector_set<T> vs1{ 1,2,3,4,5 };
	vector_set<T> vs2;
	vs2 = move(vs1);
	BOOST_CHECK_EQUAL(vs1.size(), 0);
	BOOST_CHECK(vs1.empty());
	BOOST_CHECK_EQUAL(*vs2.begin(), 1);
	BOOST_CHECK(!vs2.empty());

	// move empty one into full one
	vector_set<T> vs3;
	vs2 = move(vs3);
	BOOST_CHECK(vs2.empty() && vs3.empty());
	BOOST_CHECK_EQUAL(vs2.size(), 0);
	BOOST_CHECK_EQUAL(vs3.size(), 0);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(initializer_assignment_operator, T, num_char_types) {

	// fill one
	vector_set<T> vs1 = { 1,2,3,4,5 };
	BOOST_CHECK_EQUAL(vs1.size(), 5);
	BOOST_CHECK(!vs1.empty());
}