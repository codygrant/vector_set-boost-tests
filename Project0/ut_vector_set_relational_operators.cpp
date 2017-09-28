/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on all relational operators of
				the vector_set class
*/
#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

// 1. '==' operator
BOOST_AUTO_TEST_CASE(relational_operator_equality_tests) {
	
	// check same sized vector_sets
	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int> vs2{ 1,2,3,4,5 };
	BOOST_CHECK(vs1 == vs2);

	// empty vectors
	vector_set<double> vs3;
	vector_set<double> vs4;
	BOOST_CHECK(vs3 == vs4);

	vector_set<char> vs5{ 'a','b','c','d','e' };
	vector_set<char> vs6{ 'a','b','c','d','e' };
	BOOST_CHECK(vs5 == vs6);

	vector_set<string> vs7{ "cody","grant","london" };
	vector_set<string> vs8{ "cody","grant","london" };
	BOOST_CHECK(vs7 == vs8);
}

// 2. '!=' operator
BOOST_AUTO_TEST_CASE(relational_operator_inequality_tests) {

	// check different sized vector_sets
	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int> vs2{ 1,2,3,4,5,6 };
	BOOST_CHECK(vs1 != vs2);

	// same size different values
	vector_set<int> vs3{ 6,7,8,9,10 };
	BOOST_CHECK(vs1 != vs3);

	vector_set<char> vs4{ 'a','b','c','d','e' };
	vector_set<char> vs5{ 'A','B','C','D','E' };
	BOOST_CHECK(vs4 != vs5);

	vector_set<string> vs6{ "cody","grant","london" };
	vector_set<string> vs7{ "CODY","GRANT","LONDON" };
	BOOST_CHECK(vs6 != vs7);
}

// 3. '<' operator
BOOST_AUTO_TEST_CASE(relational_operator_less_than_tests) {

	// check different sized vector_sets
	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int> vs2{ 1,2,3,4,5,6 };
	BOOST_CHECK(vs1 < vs2);

	// same size different values
	vector_set<int> vs3{ 4,5,6,7,8 };
	BOOST_CHECK(vs1 < vs3);

	// empty one
	vector_set<int> vs4;
	BOOST_CHECK(vs4 < vs1);

	vector_set<char> vs5{ 'a','b','c','d','e' };
	vector_set<char> vs6{ 'A','B','C','D','E' };
	BOOST_CHECK(vs5 != vs6);

	vector_set<string> vs7{ "cody","grant","london" };
	vector_set<string> vs8{ "CODY","GRANT","LONDON" };
	BOOST_CHECK(vs7 != vs8);
}

// 4. '>' operator
BOOST_AUTO_TEST_CASE(relational_operator_greater_than_tests) {


}

// 5. '>=' operator
BOOST_AUTO_TEST_CASE(relational_operator_greater_than_equal_tests) {


}

// 6. '<=' operator
BOOST_AUTO_TEST_CASE(relational_operator_less_than_equal_tests) {


}