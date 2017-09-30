/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on insert() functions of the vector_set class
*/

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

using num_char_types = boost::mpl::list<short, int, long, long long, char, double>;

// 1. insert() into an empty vector_set
BOOST_AUTO_TEST_CASE_TEMPLATE(insert_empty_tests, T, num_char_types) {

	vector_set<T> vs1;
	vs1.insert(7);
	BOOST_CHECK(!vs1.empty());
	BOOST_CHECK(*vs1.begin() == 7);

	// try on string
	vector_set<string> vs2;
	vs2.insert("insert");
	BOOST_CHECK(!vs2.empty());
	BOOST_CHECK(*vs2.begin() == "insert");
}

// 2. insert() into a loaded vector_set
BOOST_AUTO_TEST_CASE_TEMPLATE(insert_loaded_tests, T, num_char_types) {

	vector_set<T> vs1{ 1,2,3,5,6,8,9 };
	vs1.insert(4);
	auto num = vs1.begin() + 3;			// create an iterator point where the 4 should be
	BOOST_CHECK_EQUAL(*num, 4);

	// try on string
	vector_set<string> vs2{ "after me", "test", "zebra" };
	vs2.insert("insert");
	BOOST_CHECK(*(vs2.begin()+1) == "insert");				// "insert" should be in element 2
	BOOST_CHECK(*vs2.begin() == "after me");				// make sure first element didn't change
}

// 3. insert() into loaded vector_set where insert value is already there
BOOST_AUTO_TEST_CASE_TEMPLATE(insert_existing_value_tests, T, num_char_types) {

	vector_set<T> vs1{ 1,2,3,5,6,8,9 };
	vs1.insert(2);
	auto num = vs1.begin() + 1;			// create an iterator point where the 2 should be
	BOOST_CHECK_EQUAL(*num, 2);			// verify it's still a 2
	BOOST_CHECK_EQUAL(*++num, 3);		// next element should be 3 since vector_set doesn't take duplicates

	// try on string
	vector_set<string> vs2{ "duplicate", "test", "zebra" };
	vs2.insert("duplicate");
	BOOST_CHECK(vs2.size() == 3);				// size should not have changed
	BOOST_CHECK(*vs2.begin() == "duplicate");	// make sure first element didn't change
}

// 4. insert() into loaded vector where capacity needs to increase
BOOST_AUTO_TEST_CASE_TEMPLATE(insert_increase_capacity_tests, T, num_char_types) {

	vector_set<T> vs1{ 5 };
	vs1.insert(9);						// capacity needs to increase from 1 to 2
	BOOST_CHECK(vs1.capacity() > 1);
	BOOST_CHECK(*vs1.begin() == 5);
	BOOST_CHECK(*(vs1.begin() + 1) == 9);

	// try on string
	vector_set<string> vs2{ "test" };
	vs2.insert("insert");
	BOOST_CHECK(vs2.capacity() > 1);
	BOOST_CHECK(*vs2.begin() == "insert");	// make sure first element is inserted value
}