namespace rhetoric {
	template <typename T>
	RangeIterator<T>::RangeIterator() : RangeIterator(nullptr, T(), T(1)) {}

	template <typename T>
	RangeIterator<T>::RangeIterator(const Range<T> * range, const T & value, const T & step) :
		range_(range), value_(value), step_(step)
	{}

	template <typename T>
	RangeIterator<T>::RangeIterator(const RangeIterator<T> & other) {
		*this = other;
	}

	template <typename T>
	RangeIterator<T> & RangeIterator<T>::operator=(const RangeIterator<T> & other) {
		range_ = other.range_;
		value_ = other.value_;
		step_ = other.step_;
		return *this;
	}

	template <typename T>
	RangeIterator<T> & RangeIterator<T>::operator++() {
		value_ = value_ + step_;
		return *this;
	}

	template <typename T>
	RangeIterator<T> RangeIterator<T>::operator++(int) {
		auto ret = *this;
		operator++();
		return ret;
	}

	template <typename T>
	RangeIterator<T> & RangeIterator<T>::operator--() {
		value_ = value_ - step_;
		return *this;
	}

	template <typename T>
	RangeIterator<T> RangeIterator<T>::operator--(int) {
		auto ret = *this;
		operator--();
		return ret;
	}

	template <typename T>
	typename RangeIterator<T>::reference RangeIterator<T>::operator*() const {
		return value_;
	}

	template <typename T>
	typename RangeIterator<T>::pointer RangeIterator<T>::operator->() const {
		return &value_;
	}

	template <typename T>
	bool RangeIterator<T>::operator==(const RangeIterator<T> & other) const {
		return (range_ == other.range_) &&
			(value_ == other.value_);
	}
}
