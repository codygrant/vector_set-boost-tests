#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_CASE(iterator_tests) {

	// 1. begin() test
	vector_set<int> vs1{ 100,200,500,300 };
	BOOST_CHECK_EQUAL(*vs1.begin(), 100);		// dereference and check first element

	// 2. end() test
	vector_set<int>::iterator it1 = vs1.end();
	--it1;										// decrement to get iterator at last element position
	BOOST_CHECK_EQUAL(*it1, 500);

	// 3. for loop
}

BOOST_AUTO_TEST_CASE(const_iterator_tests) {

	// 1. cbegin() test

	// 2. cend() test

	// 3. const begin() test

	// 4. const end() test
}

BOOST_AUTO_TEST_CASE(reverse_iterator_tests) {

	// 1. rbegin() test

	// 2. rend() test

	// 3. crbegin() test

	// 4. crend() test

	// 5. const rbegin() test

	// 6. const rend() test
}