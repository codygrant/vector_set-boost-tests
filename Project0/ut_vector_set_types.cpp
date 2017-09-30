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
using test_types = boost::mpl::list<short, int, long, long long, double, char, std::string>;
BOOST_AUTO_TEST_CASE_TEMPLATE(type_test, T, test_types) {

	BOOST_CHECK(typeid(vector_set<T>::key_type) == typeid(T));
	BOOST_CHECK(typeid(vector_set<T>::value_type) == typeid(T));
	BOOST_CHECK(typeid(vector_set<T>::size_type) == typeid(std::size_t));
	BOOST_CHECK(typeid(vector_set<T>::difference_type) == typeid(std::ptrdiff_t));
	BOOST_CHECK(typeid(vector_set<T>::key_compare) == typeid(std::less<T>));
	BOOST_CHECK(typeid(vector_set<T>::value_compare) == typeid(std::less<T>));
	BOOST_CHECK(typeid(vector_set<T>::reference) == typeid(vector_set<T>::value_type&));
	BOOST_CHECK(typeid(vector_set<T>::const_reference) == typeid(const vector_set<T>::value_type&));
	BOOST_CHECK(typeid(vector_set<T>::pointer) == typeid(vector_set<T>::value_type*));
	BOOST_CHECK(typeid(vector_set<T>::const_pointer) == typeid(vector_set<T>::value_type const*));
	BOOST_CHECK(typeid(vector_set<T>::iterator) == typeid(vector_set<T>::const_pointer));
	BOOST_CHECK(typeid(vector_set<T>::const_iterator) == typeid(vector_set<T>::const_pointer));
	BOOST_CHECK(typeid(vector_set<T>::reverse_iterator) == typeid(std::reverse_iterator<vector_set<T>::iterator>));
	BOOST_CHECK(typeid(vector_set<T>::const_reverse_iterator) == typeid(std::reverse_iterator<vector_set<T>::const_iterator>));
}