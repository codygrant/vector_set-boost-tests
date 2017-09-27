/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on all capacity functions of the vector_set class
*/

#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

// 1. Empty()
BOOST_AUTO_TEST_CASE(capacity_empty_tests) {

	vector_set<size_t> vs1;
	BOOST_CHECK(vs1.empty());
	vector_set<unsigned char> vs2{ 'a','z','t' };
	BOOST_CHECK(!vs2.empty());
	vector_set<string> vs3{ "cody","grant","london","fanshawe" };
	BOOST_CHECK_EQUAL(vs3.empty(), false);
}

// 2. Size()
BOOST_AUTO_TEST_CASE(capacity_size_tests) {

	vector_set<size_t> vs1;
	BOOST_CHECK_EQUAL(vs1.size(), 0);
	vector_set<unsigned char> vs2{ 'a','z','t' };
	BOOST_CHECK_EQUAL(vs2.size(), 3);
	vector_set<string> vs3{ "cody","grant","london","fanshawe" };
	unsigned vs3_size = vs3.size();			// store in a variable and check
	BOOST_CHECK(vs3_size == 4);
}

// 3. Capacity
BOOST_AUTO_TEST_CASE(capacity_tests) {

	// check capacity of various sized containers
	vector_set<size_t> vs1;
	BOOST_CHECK_EQUAL(vs1.capacity(), 0);	// an un-initialized STL container should have cap = 0
	vector_set<unsigned char> vs2{ 'a','z','t' };
	BOOST_CHECK(vs2.capacity() >= 3);
	vector_set<double> vs3{ 67.8,47.9,106.9,6,95.9,25.7,10.8,174.7,11.6,7.8 };
	unsigned vs3_size = vs3.size();
	BOOST_CHECK_EQUAL(vs3_size, 10);
}

// 4. Max_size()
BOOST_AUTO_TEST_CASE(capacity_max_size_tests) {

	//vector_set<char> vs2;
	//cout << (double)numeric_limits<char>::max() << endl;
	//cout << sizeof(char) << endl;
	//cout << vs2.max_size() << endl;
	//vector_set<short> vs3;
	//cout << vs3.max_size() << endl;
	//vector_set<long long> vs4;
	//cout << vs4.max_size() << endl;
}