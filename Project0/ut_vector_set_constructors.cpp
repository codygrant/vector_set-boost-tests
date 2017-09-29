/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on all constructor types of the vector_set class
*/

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

using constructor_types = boost::mpl::list<int, long, char, double, std::string>;

// 1. Destructor
BOOST_AUTO_TEST_CASE_TEMPLATE(destructor, T, constructor_types) {

	vector_set<T> vs;
}

// 2. Default constructor
BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor, T, constructor_types) {

	vector_set<T> vs;
	BOOST_CHECK(vs.size() == 0);
	BOOST_CHECK(vs.empty());
}

// 3. Copy constructor
BOOST_AUTO_TEST_CASE(copy_constructor) {

	// fill one
	vector_set<size_t> vs1 = { 1,2,3,4,5 };
	// copy filled one into new one
	vector_set<size_t> vs2(vs1);
	BOOST_CHECK_EQUAL(vs1.size(), vs2.size());
	BOOST_CHECK_EQUAL(*vs1.begin(), *vs2.begin());	// check that the values are the same
	BOOST_CHECK(!vs2.empty());
}

// 4. Move constructor
BOOST_AUTO_TEST_CASE(move_constructor) {

	// fill one
	vector_set<size_t> vs1 = { 1,2,3,4,5 };
	size_t original_size = vs1.size();
	// move filled one into new one
	vector_set<size_t> vs2(move(vs1));
	BOOST_CHECK(vs1.empty());
	BOOST_CHECK(!vs2.empty());
	BOOST_CHECK_EQUAL(vs2.size(), original_size);
}

// 5. Initializer list constructor

// 6. Auto-fill constructor
BOOST_AUTO_TEST_CASE(autofill_constructor) {

	
}