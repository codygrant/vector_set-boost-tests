/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on the clear() modifier function of 
				the vector_set class
*/
#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

// 1. clear() function - Number types
using number_types = boost::mpl::list<int, long, double, short, unsigned>;
BOOST_AUTO_TEST_CASE_TEMPLATE(clear_number_types_test, T, number_types) {

	vector_set<T> vs1{7, 9, 3, 30, 2, 54, 21, 5, 9, 17};
	vs1.clear();
	BOOST_CHECK(vs1.size() == 0);
	BOOST_CHECK(vs1.empty());
}

// 2. clear function() - Char type
BOOST_AUTO_TEST_CASE(clear_char_test) {

	vector_set<char> vs1{ 'h','r','>','8','f','b' };
	vs1.clear();
	BOOST_CHECK(vs1.size() == 0);
	BOOST_CHECK(vs1.empty());
}

// 3. clear() function - string type
BOOST_AUTO_TEST_CASE(clear_string_test) {

	vector_set<string> vs1{ "cody","GRANT", "loNDon", "BOOST", "TEST" };
	vs1.clear();
	BOOST_CHECK(vs1.size() == 0);
	BOOST_CHECK(vs1.empty());
}

// 4. try to clear un-initialized vector_set
BOOST_AUTO_TEST_CASE(clear_unitialized_test) {

	vector_set<string> vs1;
	vs1.clear();
	BOOST_CHECK(vs1.size() == 0);
	BOOST_CHECK(vs1.empty());
}