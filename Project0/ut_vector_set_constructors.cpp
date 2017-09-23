#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

using constructor_types = boost::mpl::list<int, long, unsigned char, double, std::string>;

BOOST_AUTO_TEST_CASE_TEMPLATE(destructor, T, constructor_types) {

	vector_set<T> vs;
}

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor, T, constructor_types) {

	vector_set<T> vs;
	BOOST_CHECK(vs.size() == 0);
	BOOST_CHECK(vs.empty());
}

BOOST_AUTO_TEST_CASE(copy_constructor) {

	// fill one
	vector_set<size_t> vs1 = { 1,2,3,4,5 };
	// copy filled one into new one
	vector_set<size_t> vs2(vs1);
	BOOST_CHECK_EQUAL(vs1.size(), vs2.size());
	BOOST_CHECK_EQUAL(*vs1.begin(), *vs2.begin());	// check that the values are the same
	BOOST_CHECK(!vs2.empty());
}