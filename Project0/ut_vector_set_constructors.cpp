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

using all_types = boost::mpl::list<short, int, long, long long, char, double, std::string>;
using num_char_types = boost::mpl::list<short, int, long, long long, char, double>;
// 1. Destructor
BOOST_AUTO_TEST_CASE_TEMPLATE(destructor, T, all_types) {

	vector_set<T> vs;
}

// 2. Default constructor
BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor, T, all_types) {

	vector_set<T> vs;
	BOOST_CHECK(vs.size() == 0);
	BOOST_CHECK(vs.empty());
}

// 3. Copy constructor
BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor, T, num_char_types) {

	// fill one
	vector_set<T>vs1 = { 1,2,3,4,5 };
	// copy filled one into new one
	vector_set<T> vs2(vs1);
	BOOST_CHECK_EQUAL(vs1.size(), vs2.size());
	BOOST_CHECK_EQUAL(*vs1.begin(), *vs2.begin());	// check that the values are the same
	BOOST_CHECK(!vs2.empty());

	// do one for strings
	vector_set<string> vs3{ "test","string","cody" };
	vector_set<string> vs4(vs3);
	BOOST_CHECK_EQUAL(vs3.size(), vs4.size());
	BOOST_CHECK_EQUAL(*vs3.begin(), *vs4.begin());	// check that the values are the same
	BOOST_CHECK(!vs3.empty());
}

// 4. Move constructor
BOOST_AUTO_TEST_CASE_TEMPLATE(move_constructor, T, num_char_types) {

	// fill one
	vector_set<T> vs1 = { 1,2,3,4,5 };
	size_t vs1_original_size = vs1.size();
	// move filled one into new one
	vector_set<T> vs2(move(vs1));
	BOOST_CHECK(vs1.empty());
	BOOST_CHECK(!vs2.empty());
	BOOST_CHECK_EQUAL(vs2.size(), vs1_original_size);

	// do one for strings
	vector_set<string> vs3{ "test","string","cody" };
	size_t vs3_original_size = vs3.size();
	vector_set<string> vs4(move(vs3));
	BOOST_CHECK(vs3.empty());
	BOOST_CHECK(!vs4.empty());
	BOOST_CHECK_EQUAL(vs4.size(), vs3_original_size);
}

// 5. Initializer list constructor
BOOST_AUTO_TEST_CASE_TEMPLATE(initializer_constructor_test, T, num_char_types) {

	vector_set<T> vs1{ 3,-7,-2,6,9,1 };
	BOOST_TEST_CHECK(*vs1.begin() == -7);		// -7 should be first element after sorted
	BOOST_TEST_CHECK(*(vs1.end() - 1) == 9);	// 9 should be last element after sorted
}

// 6. Auto-fill constructor
BOOST_AUTO_TEST_CASE_TEMPLATE(autofill_constructor, T, num_char_types) {

	// throw it a full vector_set to autofill
	vector_set<T> vs1{ 1,2,3,4,5,6,7,8 };
	auto it1 = vs1.begin();
	auto it2 = vs1.end();
	vector_set<T> vs2(it1, it2);
	BOOST_CHECK_EQUAL(vs1.size(), vs2.size());
	BOOST_CHECK_EQUAL(*vs1.begin(), *vs2.begin());
	BOOST_CHECK_EQUAL(*(vs1.end()-1), *(vs2.end()-1));

	// select a different range
	++it1;
	it2 -= 2;
	vector_set<T> vs3(it1, it2);
	// new vector should hold 2 - 6
	BOOST_CHECK(vs3.size() == 5);
	BOOST_CHECK(*vs3.begin() == 2);
	BOOST_CHECK(*(vs3.end()-1) == 6);
}