#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_CASE(copy_assignment_operator) {

	// fill one
	vector_set<size_t> vs1 = { 1,2,3,4,5 };
	vector_set<size_t> vs2;
	vs2 = vs1;
	BOOST_CHECK_EQUAL(vs1.size(), vs2.size());
	BOOST_CHECK_EQUAL(*vs1.begin(), *vs2.begin());	// check that the values are the same
	BOOST_CHECK(!vs2.empty());

	// transfer empty one into full one
	vector_set<size_t> vs3;
	vs2 = vs3;
	BOOST_CHECK(vs2.empty());
	BOOST_CHECK_EQUAL(vs2.size(), 0);
}