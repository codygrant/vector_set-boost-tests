#pragma once

/**	@file vector_set.hpp
	@author Garth Santor
	@date 2017-08-31

	vector_set template class.
*/

#include <algorithm>
#include <cstddef>
#include <functional>
#include <initializer_list>


template <class Key>
class vector_set {

	// TYPES
public:
	using key_type = Key;
	using value_type = Key;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;
	using key_compare = std::less<Key>;
	using value_compare = std::less<Key>;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = value_type const *;
	using iterator = const_pointer;
	using const_iterator = const_pointer;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;


	// ATTRIBUTES
private:
	pointer beg_;
	pointer end_;
	pointer cap_;
	// OPERATIONS
public:
	// constructors
	~vector_set() { delete[] beg_; }
	vector_set() : beg_(nullptr), end_(nullptr), cap_(nullptr) {}
	vector_set(vector_set const& other);
	vector_set(vector_set && other) noexcept;
	vector_set(std::initializer_list<value_type> init);
	template <class FORWARD>
	vector_set(FORWARD first, FORWARD last) {
		while (first != last)
			insert(*first++);
	}

	// iterators
	iterator begin() noexcept { return iterator(beg_); }
	iterator end() noexcept { return iterator(end_); }
	const_iterator cbegin() const noexcept { return const_iterator(beg_); }
	const_iterator cend() const noexcept { return const_iterator(end_); }
	const_iterator begin() const noexcept { return cbegin(); }
	const_iterator end() const noexcept { return cend(); }

	reverse_iterator rbegin() noexcept { return reverse_iterator(end_); }
	reverse_iterator rend() noexcept { return reverse_iterator(beg_); }
	const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end_); }
	const_reverse_iterator crend() const noexcept { return const_reverse_iterator(beg_); }
	const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end_); }
	const_reverse_iterator rend() const noexcept { return const_reverse_iterator(beg_); }

	// capacity
	bool empty() const noexcept { return size() == 0; }
	size_type size() const noexcept { return end_ - beg_; }
	size_type capacity() const noexcept { return cap_ - beg_; }
	size_type max_size() const noexcept { return std::numeric_limits<size_type>::max() / sizeof(value_type); }

	// modifiers
	void clear() noexcept;
	std::pair<iterator, bool> insert(const value_type& value);
	iterator erase(const_iterator pos);
	iterator erase(const_iterator first, const_iterator last);
	void swap(vector_set& other) noexcept;

	// lookup
	iterator find(const Key& key);
	const_iterator lower_bound(const Key& key) const;

	// member operators
	vector_set& operator = (vector_set const& other);
	vector_set& operator = (vector_set && other) noexcept;
	vector_set& operator = (std::initializer_list<value_type> ilist);
};



// Helper functions
template <class Key>
inline void swap(vector_set<Key>& lhs, vector_set<Key>& rhs) {
	lhs.swap(rhs);
}

template <class Key>
typename vector_set<Key>::iterator begin(vector_set<Key>& vs) { return vs.begin(); }

template <class Key>
typename vector_set<Key>::iterator end(vector_set<Key>& vs) { return vs.end(); }


// Relational operators
template <class Key>
bool operator == (vector_set<Key> const& lhs, vector_set<Key> const& rhs) {
	if (lhs.size() != rhs.size())
		return false;

	auto left = lhs.begin();
	auto right = rhs.begin();
	while (left != lhs.end())
		if (*left++ != *right++)
			return false;

	return true;
}
template <class Key> inline bool operator != (vector_set<Key> const& lhs, vector_set<Key> const& rhs) { return !(lhs == rhs); }

template <class Key>
bool operator < (vector_set<Key> const& lhs, vector_set<Key> const& rhs) {
	auto left = lhs.begin();
	auto right = rhs.begin();
	while (left != lhs.end() && right != rhs.end()) {
		if (*left < *right)
			return true;
		else if (*left > *right)
			return false;
		++left, ++right;
	}
	if (right==rhs.end())
		return false;

	return true;
}
template <class Key> inline bool operator > (vector_set<Key> const& lhs, vector_set<Key> const& rhs) { return rhs < lhs; }
template <class Key> inline bool operator >= (vector_set<Key> const& lhs, vector_set<Key> const& rhs) { return !(lhs<rhs); }
template <class Key> inline bool operator <= (vector_set<Key> const& lhs, vector_set<Key> const& rhs) { return !(rhs<lhs); }



// =============================================================================================================
// IMPLEMENTATIONS
// =============================================================================================================

// vector_set::operator = (copy)
template <class Key>
vector_set<Key>& vector_set<Key>::operator = (vector_set<Key> const& other) {
	// make a new buffer if necessary
	if (capacity() < other.size()) {
		auto newBuffer = new value_type[other.size()];
		delete[]beg_;
		beg_ = end_ = newBuffer;
		cap_ = beg_ + other.size();
	}
	auto from = other.beg_;
	end_ = beg_;
	while (from != other.end_)
		*end_++ = *from++;

	return *this;
}



// vector_set::operator = (move)
template <class Key>
vector_set<Key>& vector_set<Key>::operator = (vector_set<Key> && other) noexcept {
	delete[] beg_;
	beg_ = other.beg_;
	end_ = other.end_;
	cap_ = other.cap_;

	other.beg_ = other.end_ = other.cap_ = nullptr;

	return *this;
}



// vector_set::operator = (initializer)
template <class Key>
vector_set<Key>& vector_set<Key>::operator = (std::initializer_list<value_type> iList) {

	vector_set<Key> newSet(iList);
	newSet.swap(*this);

	return *this;
}



// vector_set copy constructor.
template <class Key>
vector_set<Key>::vector_set(vector_set<Key> const& other) : vector_set() {
	end_ = beg_ = new value_type[other.size()];
	cap_ = beg_ + other.size();
	for (auto e : other)
		*end_++ = e;
}



// vector_set R-value constructor.
template <class Key>
vector_set<Key>::vector_set(vector_set<Key> && other) noexcept : beg_(other.beg_), end_(other.end_), cap_(other.cap_) {
	other.beg_ = other.end_ = other.cap_ = nullptr;
}



// vector_set initializer list constructor.
template <class Key>
vector_set<Key>::vector_set(std::initializer_list<value_type> init) : vector_set() {
	for (auto e : init)
		insert(e);
}



// vector_set::clear method removes all elements from the container.
template <class Key>
void vector_set<Key>::clear() noexcept {
	while (end_ != beg_) {
		--end_;
		*end_ = std::move(Key());
	}
}



// vector_set::erase a single element
template <class Key>
typename vector_set<Key>::iterator vector_set<Key>::erase(const_iterator pos) {
	value_type* to = const_cast<value_type*>(pos);
	while (to != end_) {
		*to = std::move(*(to + 1));
		++to;
	}
	--end_;

	return pos;
}



// vector_set::erase a range of elements
template <class Key>
typename vector_set<Key>::iterator vector_set<Key>::erase(const_iterator first, const_iterator last) {
	auto to = const_cast<pointer>(first);
	auto from = const_cast<pointer>(last);
	while (from != end_) {
		*to = std::move(*from);
		++to, ++from;
	}
	end_ = to;

	return first;
}



// vector_set::lower_bound method
template <class Key>
typename vector_set<Key>::const_iterator vector_set<Key>::lower_bound(const Key& key) const {
	auto low = beg_;
	auto high = end_;
	auto count = high - low;
	while (count > 0) {
		auto step = count / 2;
		auto split = low + step;
		if (*split < key) {
			low = ++split;
			count -= step + 1;
		}
		else
			count = step;
	}
	return low;
}



// vector_set::find method
template <class Key>
typename vector_set<Key>::iterator vector_set<Key>::find(const Key& key) {
	auto pos = lower_bound(key);
	if (pos != end_ && *pos == key)
		return pos;
	else
		return end();
}



// vector_set insert method
template <class Key>
std::pair<typename vector_set<Key>::iterator, bool> vector_set<Key>::insert(const value_type& value) {
	if (capacity()==0) {
		beg_ = new value_type[1];
		*beg_ = value;
		cap_ = end_ = beg_ + 1;
		return std::make_pair(iterator(beg_), true);
	}
	// where should we insert the value?
	auto insertLocation = std::lower_bound(beg_, end_, value);

	// is there one there already?
	if (insertLocation != end_ && value == *insertLocation)
		return std::make_pair(iterator(insertLocation), false);

	// is there enought space?
	if (cap_ == end_) {
		// make expanded memory block.
		auto newCap = size() * 2;
		auto newBeg = new value_type[newCap];

		// copy up to the insertion point
		auto from = beg_;
		auto to = newBeg;
		while (from != insertLocation)
			*to++ = *from++;

		// insert the new element
		insertLocation = to;
		*to++ = value;

		// copy the rest
		while (from != end_)
			*to++ = *from++;

		// replace
		delete[] beg_;
		beg_ = newBeg;
		end_ = to;
		cap_ = beg_ + newCap;

		return std::make_pair(iterator(insertLocation), true);
	}

	// bump up everything from the insertion point to the end
	auto from = end_++;
	while (insertLocation != from) {
		auto to = from--;
		*to = *from;
	}
	*insertLocation = value;
	return std::make_pair(iterator(insertLocation), true);
}




template <class Key>
void vector_set<Key>::swap(vector_set& other) noexcept {
	std::swap(beg_, other.beg_);
	std::swap(end_, other.end_);
	std::swap(cap_, other.cap_);
}
