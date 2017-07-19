#pragma once

#include "./std_dependency.h"

#include "./concept_macro.h"

namespace rhetoric {
	template <typename T> class Range;

	template <typename T>
	class RangeIterator :
		public std::iterator<
		std::bidirectional_iterator_tag,
		T,
		std::ptrdiff_t,
		const T *,
		const T &>
	{
	public:
		RangeIterator(const Range<T> * range, const T & value, const T & step);
		RangeIterator(const RangeIterator<T> & other);

		RangeIterator<T> & operator=(const RangeIterator<T> & other);

		RangeIterator<T> & operator++();
		RangeIterator<T> operator++(int);
		RangeIterator<T> & operator--();
		RangeIterator<T> operator--(int);
        const T & operator*() const;
        const T * operator->() const;
		bool operator==(const RangeIterator<T> & other) const;
		RHETORIC_EQUATABLE_DEFAULT(RangeIterator<T>)
	private:
		const Range<T> * range_;
		T value_;
		T step_;
	};

}

#include "./range_iterator_inline.h"
