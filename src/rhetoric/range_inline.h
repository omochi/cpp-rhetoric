namespace rhetoric {
    template <typename T>
    Range<T>::Iterator::Iterator():
    range_(nullptr),
    value_()
    {}

    template <typename T>
    Range<T>::Iterator::Iterator(const Range<T> * range, T value):
    range_(range),
    value_(value)
    {}

    template <typename T>
    Range<T>::Iterator::Iterator(const Iterator & other)
    {
        *this = other;
    }

    template <typename T>
    typename Range<T>::Iterator & Range<T>::Iterator::operator=(const Range<T>::Iterator & other) {
        range_ = other.range_;
        value_ = other.value_;
        return *this;
    }

    template <typename T>
    typename Range<T>::Iterator & Range<T>::Iterator::operator++() {
        value_ = std::min(value_ + static_cast<T>(1), range_->upper_bound_);
        return *this;
    }

    template <typename T>
    typename Range<T>::Iterator Range<T>::Iterator::operator++(int) {
        auto ret = *this;
        ++*this;
        return ret;
    }

    template <typename T>
    typename Range<T>::Iterator & Range<T>::Iterator::operator--() {
        value_ = std::max(value_ - static_cast<T>(1), range_->lower_bound_);
        return *this;
    }

    template <typename T>
    typename Range<T>::Iterator Range<T>::Iterator::operator--(int) {
        auto ret = *this;
        --*this;
        return ret;
    }

    template <typename T>
    const T & Range<T>::Iterator::operator*() const {
        return value_;
    }

    template <typename T>
    const T * Range<T>::Iterator::operator->() const {
        return &value_;
    }

    template <typename T>
    bool Range<T>::Iterator::operator==(const Range<T>::Iterator & other)
    const {
        return value_ == other.value_;
    }

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
    decltype(std::declval<T>() - std::declval<T>()) Range<T>::count() const {
        return static_cast<int>(upper_bound_ - lower_bound_);
    }

    template <typename T>
    typename Range<T>::Iterator Range<T>::begin() const {
        return Iterator(this, lower_bound_);
    }

    template <typename T>
    typename Range<T>::Iterator Range<T>::end() const {
        return Iterator(this, upper_bound_);
    }

    template <typename T>
    T Range<T>::Blend(double rate) const {
        return lower_bound_ + (upper_bound_ - lower_bound_) * rate;
    }

    template <typename T>
    double Range<T>::GetRate(const T & value) const {
        return static_cast<double>(value - lower_bound_) / (upper_bound_ - lower_bound_);
    }

    template <typename T>
    Range<T> MakeRange(const T & lower_bound, const T & upper_bound) {
        return Range<T>(lower_bound, upper_bound);
    }

}
