#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

// 1. begin() test
BOOST_AUTO_TEST_CASE(iterator_begin_tests) {

	vector_set<int> vs1{ 100,200,300,400 };
	vector_set<int>::iterator beg = vs1.begin();
	BOOST_CHECK_EQUAL(*beg, 100);		// dereference and check first element
}

// 2. end() test
BOOST_AUTO_TEST_CASE(iterator_end_tests) {

	vector_set<int> vs1{ 100,200,300,400 };
	vector_set<int>::iterator beg = vs1.begin();
	vector_set<int>::iterator end = vs1.end();
	// do some comparisons first
	BOOST_CHECK_EQUAL(end - beg, 4);			// difference in elements should be 4
	BOOST_CHECK(beg < end);						// beg iterator should be "before" end iterator

	--end;										// decrement to get iterator at last element position
	BOOST_CHECK_EQUAL(*end, 400);
}

// 3. begin() and end() loop tests
BOOST_AUTO_TEST_CASE(iterator_begin_end_loop_tests) {

	vector_set<int> vs1{ 100,200,300,400 };
	vector_set<int>::iterator beg = vs1.begin();
	vector_set<int>::iterator end = vs1.end();
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

// 4. cbegin() test
BOOST_AUTO_TEST_CASE(iterator_cbegin_tests) {

	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::const_iterator c_beg = vs1.cbegin();
	BOOST_CHECK_EQUAL(*c_beg, 1);
}

// 4. cend() test
BOOST_AUTO_TEST_CASE(iterator_cend_tests) {

	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::const_iterator c_beg = vs1.cbegin();
	vector_set<int>::const_iterator c_end = vs1.cend();
	// do some comparisons first
	BOOST_CHECK_EQUAL(c_end - c_beg, 5);
	BOOST_CHECK(c_beg < c_end);

	--c_end;
	BOOST_CHECK_EQUAL(*c_end, 5);
}

// 5. cbegin() and cend() loop tests
BOOST_AUTO_TEST_CASE(iterator_cbegin_cend_loop_tests) {

	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::const_iterator c_beg = vs1.cbegin();
	vector_set<int>::const_iterator c_end = vs1.cend();

	// make sure it increments correctly
	int value = 1;
	while (c_beg != c_end) {
		BOOST_CHECK_EQUAL(*c_beg, value);
		++c_beg, ++value;
	}

	// make sure it increments down correctly
	--c_end;
	while (c_end >= c_beg) {
		BOOST_CHECK_EQUAL(*c_end, value);
		--c_beg, --value;
	}
}

// 6. const begin() test
BOOST_AUTO_TEST_CASE(iterator_const_begin_tests) {
	vector_set<char> vs1{ 'd','a','c','e','b' };
	vector_set<char>::const_iterator const_beg = vs1.begin();
	BOOST_CHECK_EQUAL(*const_beg, 'a');
}

// 7. const end() test
BOOST_AUTO_TEST_CASE(iterator_const_end_tests) {
	vector_set<char> vs1{ 'd','a','c','e','b' };
	vector_set<char>::const_iterator const_beg = vs1.begin();
	vector_set<char>::const_iterator const_end = vs1.end();

	// do some comparisons first
	BOOST_CHECK_EQUAL(const_end - const_beg, 5);
	BOOST_CHECK(const_beg < const_end);

	--const_end;
	BOOST_CHECK_EQUAL(*const_end, 'e');
}

// 8. const begin() and const end() loop tests
BOOST_AUTO_TEST_CASE(iterator_const_begin_const_end_loop_tests) {

	vector_set<char> vs1{ 'd','a','c','e','b' };
	vector_set<char>::const_iterator const_beg = vs1.begin();
	vector_set<char>::const_iterator const_end = vs1.end();

	// make sure it increments correctly
	int value = 'a';
	while (const_beg != const_end) {
		BOOST_CHECK_EQUAL(*const_beg, value);
		++const_beg, ++value;
	}

	// make sure it increments down correctly
	--const_end;
	while (const_end >= const_beg) {
		BOOST_CHECK_EQUAL(*const_end, value);
		--const_beg, --value;
	}
}

// 9. rbegin() test
BOOST_AUTO_TEST_CASE(iterator_rbegin_tests) {

	vector_set<int> vs1{ 100,200,300,400 };
	vector_set<int>::reverse_iterator rbeg = vs1.rbegin();
	BOOST_CHECK_EQUAL(*rbeg, 400);		// dereference and check first element
}

// 10. rend() test
BOOST_AUTO_TEST_CASE(iterator_rend_tests) {

	vector_set<int> vs1{ 100,200,300,400 };
	vector_set<int>::reverse_iterator rbeg = vs1.rbegin();
	vector_set<int>::reverse_iterator rend = vs1.rend();
	// do some comparisons first
	BOOST_CHECK_EQUAL(rend - rbeg, 4);			// difference in elements should be 4
	BOOST_CHECK(rbeg < rend);					// beg iterator should still be "before" end iterator

	--rend;										// decrement iterator to move it to first element
	BOOST_CHECK_EQUAL(*rend, 100);
}

// 11. rbegin() and rend() loop tests
BOOST_AUTO_TEST_CASE(iterator_rbegin_rend_loop_tests) {

	vector_set<int> vs1{ 100,200,300,400 };
	vector_set<int>::reverse_iterator rbeg = vs1.rbegin();
	vector_set<int>::reverse_iterator rend = vs1.rend();
	// make sure it increments "up"/reverses correctly
	int value = 400;
	while (rbeg != rend) {
		BOOST_CHECK_EQUAL(*rbeg, value);
		++rbeg, value -= 100;
	}
	// make sure it increments "down" correctly
	--rend;
	while (rend >= rbeg) {
		BOOST_CHECK_EQUAL(*rend, value);
		--rbeg, value += 100;
	}
}

// 12. crbegin() test
BOOST_AUTO_TEST_CASE(iterator_crbegin_tests) {

	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::const_reverse_iterator cr_beg = vs1.crbegin();
	BOOST_CHECK_EQUAL(*cr_beg, 5);
}

// 13. crend() test
BOOST_AUTO_TEST_CASE(iterator_crend_tests) {

	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::const_reverse_iterator cr_beg = vs1.crbegin();
	vector_set<int>::const_reverse_iterator cr_end = vs1.crend();
	// do some comparisons first
	BOOST_CHECK_EQUAL(cr_end - cr_beg, 5);
	BOOST_CHECK(cr_beg < cr_end);

	--cr_end;
	BOOST_CHECK_EQUAL(*cr_end, 1);
}

// 14. crbegin() and crend() loop tests
BOOST_AUTO_TEST_CASE(iterator_crbegin_crend_loop_tests) {

	vector_set<int> vs1{ 1,2,3,4,5 };
	vector_set<int>::const_reverse_iterator cr_beg = vs1.crbegin();
	vector_set<int>::const_reverse_iterator cr_end = vs1.crend();

	// make sure it reverses correctly
	int value = 5;
	while (cr_beg != cr_end) {
		BOOST_CHECK_EQUAL(*cr_beg, value);
		++cr_beg, --value;
	}

	// make sure it increments down correctly
	--cr_end;
	while (cr_end >= cr_beg) {
		BOOST_CHECK_EQUAL(*cr_end, value);
		--cr_beg, ++value;
	}
}

// 15. const rbegin() test
BOOST_AUTO_TEST_CASE(iterator_const_rbegin_tests) {
	vector_set<char> vs1{ 'd','a','c','e','b' };
	vector_set<char>::const_reverse_iterator const_rbeg = vs1.rbegin();
	BOOST_CHECK_EQUAL(*const_rbeg, 'e');
}

// 16. const rend() test
BOOST_AUTO_TEST_CASE(iterator_const_rend_tests) {
	vector_set<char> vs1{ 'd','a','c','e','b' };
	vector_set<char>::const_reverse_iterator const_rbeg = vs1.rbegin();
	vector_set<char>::const_reverse_iterator const_rend = vs1.rend();

	// do some comparisons first
	BOOST_CHECK_EQUAL(const_rend - const_rbeg, 5);
	BOOST_CHECK(const_rbeg < const_rend);

	--const_rend;			// decrement to get it to fist element
	BOOST_CHECK_EQUAL(*const_rend, 'a');
}

// 17. const rbegin() and const rend() loop tests
BOOST_AUTO_TEST_CASE(iterator_const_rbegin_const_rend_loop_tests) {

	vector_set<char> vs1{ 'd','a','c','e','b' };
	vector_set<char>::const_reverse_iterator const_rbeg = vs1.rbegin();
	vector_set<char>::const_reverse_iterator const_rend = vs1.rend();

	// make sure it increments correctly
	int value = 'e';
	while (const_rbeg != const_rend) {
		BOOST_CHECK_EQUAL(*const_rbeg, value);
		++const_rbeg, --value;
	}

	// make sure it increments down correctly
	--const_rend;
	while (const_rend >= const_rbeg) {
		BOOST_CHECK_EQUAL(*const_rend, value);
		--const_rbeg, ++value;
	}
}
