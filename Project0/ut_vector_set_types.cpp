/*
Name:			Cody Grant
Date:			Sept 29, 2017
Purpose:		Perform Boost Tests on type definitions of
				the vector_set class
*/

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

#include "vector_set.hpp"
#include <iostream>
using namespace std;

#include <typeinfo>
using test_types = boost::mpl::list<int, long, double, char, std::string>;
BOOST_AUTO_TEST_CASE_TEMPLATE(type_test, T, test_types) {

	//BOOST_CHECK(typeid(vector_set<T>::value_type) == typeid(std::string));
	//BOOST_CHECK(typeid(vector_set<T>::reference) == typeid(std::string&));
	//BOOST_CHECK(typeid(vector_set<T>::const_reference) == typeid(std::string const&));
	//BOOST_CHECK(typeid(vector_set<T>::size_type) == typeid(std::size_t));
}