#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_CASE(iterator_tests) {

	// 1. begin() test
	vector_set<int> vs1{ 100,200,300,400 };
	vector_set<int>::iterator beg = vs1.begin();
	BOOST_CHECK_EQUAL(*vs1.begin(), 100);		// dereference and check first element

	// 2. end() test
	vector_set<int>::iterator end = vs1.end();
	// do some comparisons first
	BOOST_CHECK_EQUAL(end - beg, 4);			// difference in elements should be 4
	BOOST_CHECK(beg < end);						// beg iterator should be "before" end iterator

	--end;										// decrement to get iterator at last element position
	BOOST_CHECK_EQUAL(*end, 400);
	++end;										// put it back to initial

	// make sure it increments up correctly
	int value = 100;
	while (beg != end) {
		BOOST_CHECK_EQUAL(*beg, value);
		++beg, value += 100;
	}
	// make sure it increments down correctly
	--end;
	while (end >= beg) {
		BOOST_CHECK_EQUAL(*end, value);
		--beg, value -= 100;
	}
}

BOOST_AUTO_TEST_CASE(const_iterator_tests) {

	// 1. cbegin() test
	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::const_iterator c_beg = vs1.cbegin();
	BOOST_CHECK_EQUAL(*vs1.begin(), 1);

	// 2. cend() test
	vector_set<int>::iterator c_end = vs1.end();
	// do some comparisons first
	BOOST_CHECK_EQUAL(c_end - c_beg, 5);
	BOOST_CHECK(c_beg < c_end);

	--c_end;
	BOOST_CHECK_EQUAL(*c_end, 5);

	// make sure it increments correctly
	int value = 1;
	while (c_beg != c_end) {
		BOOST_CHECK_EQUAL(*c_beg, value);
		++c_beg, ++value;
	}

	// 3. const begin() test

	// 4. const end() test
}

BOOST_AUTO_TEST_CASE(reverse_iterator_tests) {

	// 1. rbegin() test
	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::reverse_iterator r_beg = vs1.rbegin();
	BOOST_CHECK_EQUAL(*r_beg, 5);			// should point to last element

	// 2. rend() test
	vector_set<int>::reverse_iterator r_end = vs1.rend();
	// do some comparisons first
	BOOST_CHECK_EQUAL(r_end - r_beg, 5);			// difference in elements should be 4
	BOOST_CHECK(r_beg < r_end);						// beg iterator should still be "before" end iterator

	--r_end;										// decrement iterator to move it to first element
	BOOST_CHECK_EQUAL(*r_end, 1);
	++r_end;										// return to 1 element "before" the container

	// 3. crbegin() test

	// 4. crend() test

	// 5. const rbegin() test

	// 6. const rend() test
}