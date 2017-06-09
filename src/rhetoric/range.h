#pragma once

#include "./comparable_macro.h"
#include "./equatable_macro.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <typename T>
    class Range {
    public:
        class Iterator :
        public std::iterator<
        std::bidirectional_iterator_tag,
        T,
        std::ptrdiff_t,
        const T *,
        const T &>
        {
        public:
            Iterator();
            Iterator(const Range<T> * range, T value);
            Iterator(const Iterator & other);

            Iterator & operator=(const Iterator & other);

            Iterator & operator++();
            Iterator operator++(int);
            Iterator & operator--();
            Iterator operator--(int);
            const T & operator*() const;
            const T * operator->() const;
            bool operator==(const Range<T>::Iterator & other) const;
            RHETORIC_EQUATABLE_DEFAULT(Range<T>::Iterator)
        private:
            const Range<T> * range_;
            T value_;
        };

        Range();
        Range(const T & lower_bound, const T & upper_bound);
        Range(const Range<T> & other);
        Range<T> & operator=(const Range<T> & other);

        T lower_bound() const;
        T upper_bound() const;
        decltype(std::declval<T>() - std::declval<T>()) count() const;

        Iterator begin() const;
        Iterator end() const;
        Iterator cbegin() const { return begin(); }
        Iterator cend() const { return end(); }

        std::reverse_iterator<Iterator> rbegin() const { return std::make_reverse_iterator(end()); }
        std::reverse_iterator<Iterator> rend() const { return std::make_reverse_iterator(begin()); }
        std::reverse_iterator<Iterator> crbegin() const { return rbegin(); }
        std::reverse_iterator<Iterator> crend() const { return rend(); }

        T Blend(double rate) const;
        double GetRate(const T & value) const;
        T Clamp(const T & value) const;
    private:
        T lower_bound_;
        T upper_bound_;
    };

    template <typename T>
    Range<T> MakeRange(const T & lower_bound, const T & upper_bound);
}

#include "./range_inline.h"
