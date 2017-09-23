#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_CASE(capacity_tests) {

	// 1. Empty
	vector_set<size_t> vs1;
	BOOST_CHECK(vs1.empty());
	vector_set<unsigned char> vs2{ 'a','z','t' };
	BOOST_CHECK(!vs2.empty());

	// 2. Size
	BOOST_CHECK_EQUAL(vs1.size(), 0);
	BOOST_CHECK_EQUAL(vs2.size(), 3);
}