/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		A project to perform Unit Tests on all aspects of the
				vector_set custom class using the Boost library.
*/

#define BOOST_TEST_MODULE Unit Tests
#include <boost/test/unit_test.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_CASE(intro) {
	cout << "\nvector_set Unit Tests" << endl;
	cout << "Last compiled: " << __TIMESTAMP__ << endl;
	cout << "---------------------------------------" << endl;

}