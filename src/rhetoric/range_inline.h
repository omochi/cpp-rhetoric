namespace rhetoric {
    template <typename T>
    Range<T>::Iterator::Iterator():
    range_(nullptr),
    value_(0)
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
        value_ = std::min(value_ + static_cast<T>(1), range_->right_);
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
        value_ = std::max(value_ - static_cast<T>(1), range_->left_);
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
    left_(0),
    right_(0)
    {}

    template <typename T>
    Range<T>::Range(const T & left, const T & right):
    left_(left),
    right_(right)
    {}

    template <typename T>
    Range<T>::Range(const Range<T> & other):
    left_(other.left_),
    right_(other.right_)
    {}

    template <typename T>
    T Range<T>::left() const {
        return left_;
    }

    template <typename T>
    T Range<T>::right() const {
        return right_;
    }

    template <typename T>
    int Range<T>::count() const {
        return static_cast<int>(right_ - left_);
    }

    template <typename T>
    typename Range<T>::Iterator Range<T>::begin() const {
        return Iterator(this, left_);
    }

    template <typename T>
    typename Range<T>::Iterator Range<T>::end() const {
        return Iterator(this, right_);
    }

    template <typename T>
    Range<T> MakeRange(const T & left, const T & right) {
        return Range<T>(left, right);
    }

}
