namespace rhetoric {
    template <typename T>
    Range<T>::Range():
    lower_bound_(),
    upper_bound_()
    {}

    template <typename T>
    Range<T>::Range(const T & lower_bound, const T & upper_bound):
    lower_bound_(lower_bound),
    upper_bound_(upper_bound)
    {}

    template <typename T>
    Range<T>::Range(const Range<T> & other)
    {
        *this = other;
    }

    template <typename T>
    Range<T> & Range<T>::operator=(const Range<T> & other) {
        lower_bound_ = other.lower_bound_;
        upper_bound_ = other.upper_bound_;
        return *this;
    }

    template <typename T>
    T Range<T>::lower_bound() const {
        return lower_bound_;
    }

    template <typename T>
    T Range<T>::upper_bound() const {
        return upper_bound_;
    }

    template <typename T>
    typename Range<T>::DistanceType Range<T>::count() const {
        return upper_bound_ - lower_bound_;
    }

    template <typename T>
    bool Range<T>::operator==(const Range<T> & other) const {
        return (lower_bound_ == other.lower_bound_) &&
        (upper_bound_ == other.upper_bound_);
    }

    template <typename T>
	RangeIterator<T> Range<T>::begin() const {
        return RangeIterator<T>(this, lower_bound_, T(1));
    }

    template <typename T>
	RangeIterator<T> Range<T>::end() const {
		return RangeIterator<T>(this, upper_bound_, T(1));
    }

	template <typename T>
	RangeIterator<T> Range<T>::rbegin() const {
		return RangeIterator<T>(this, upper_bound_ + T(-1), T(-1));
	}

	template <typename T>
	RangeIterator<T> Range<T>::rend() const {
		return RangeIterator<T>(this, lower_bound_ + T(-1), T(-1));
	}

    template <typename T>
    template <typename R>
    T Range<T>::Blend(R rate) const {
        return lower_bound_ + static_cast<DistanceType>(static_cast<R>(count()) * rate);
    }

    template <typename T>
    template <typename F>
    auto Range<T>::Map(F && f) const
    -> Range<decltype(f(std::declval<T>()))>
    {
        return MakeRange(f(lower_bound_), f(upper_bound_));
    }

    template <typename T>
    bool Range<T>::Contains(const T & value) const {
        return lower_bound_ <= value && value < upper_bound_;
    }

    template <typename T>
    Range<T> MakeRange(const T & lower_bound, const T & upper_bound) {
        return Range<T>(lower_bound, std::max(lower_bound, upper_bound));
    }
    
    template <typename T, typename R>
    R GetRate(const T & value, const Range<T> & range) {
        return static_cast<R>(value - range.lower_bound()) / static_cast<R>(range.count());
    }
    
    template <typename T, typename R>
    T Clamp(const T & value, const Range<T> & range) {
        return std::max(range.lower_bound(), std::min(value, range.upper_bound()));
    }

}
