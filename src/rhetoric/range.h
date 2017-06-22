#pragma once

#include "./equatable_macro.h"
#include "./range_iterator.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <typename T>
    class Range {
    public:
        using DistanceType = decltype(std::declval<T>() - std::declval<T>());

        Range();
        Range(const T & lower_bound, const T & upper_bound);
        Range(const Range<T> & other);
        Range<T> & operator=(const Range<T> & other);

        T lower_bound() const;
        T upper_bound() const;
        DistanceType count() const;

        bool operator==(const Range<T> & other) const;
        RHETORIC_EQUATABLE_DEFAULT(Range<T>)

        RangeIterator<T> begin() const;
		RangeIterator<T> end() const;
		RangeIterator<T> cbegin() const { return begin(); }
		RangeIterator<T> cend() const { return end(); }

		RangeIterator<T> rbegin() const;
		RangeIterator<T> rend() const;
		RangeIterator<T> crbegin() const { return rbegin(); }
		RangeIterator<T> crend() const { return rend(); }

        T Blend(double rate) const;
        double GetRate(const T & value) const;
        T Clamp(const T & value) const;

        template <typename F>
        auto Map(F && f) const
        -> Range<decltype(f(std::declval<T>()))>;

        bool Contains(const T & value) const;
    private:
        T lower_bound_;
        T upper_bound_;
    };

    template <typename T>
    Range<T> MakeRange(const T & lower_bound, const T & upper_bound);
}

#include "./range_inline.h"
