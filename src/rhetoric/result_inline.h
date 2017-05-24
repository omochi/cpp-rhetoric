namespace rhetoric {

    template <typename T>
    Result<T>::Result(const T & value, ResultSuccessTag tag):
    value_(Some(value))
    {}

    template <typename T>
    Result<T>::Result(const ResultFailure & failure) {
        RHETORIC_ASSERT(failure.error != nullptr);
        error_ = failure.error;
    }

    template <typename T>
    Result<T>::Result(const Result<T> & other)
    {
        *this = other;
    }

    template <typename T>
    Result<T> & Result<T>::operator=(const Result<T> & other) {
        value_ = other.value_;
        error_ = other.error_;
        return *this;
    }

    template <typename T>
    template <typename U>
    Result<T>::Result(const Result<U> & other,
                      typename std::enable_if<std::is_convertible<U, T>::value>::type * enabler)
    {
        if (other) {
            value_ = other.value();
        } else {
            error_ = other.error();
        }
    }

    template <typename T>
    Result<T>::~Result()
    {}

    template <typename T>
    bool Result<T>::succeeded() const {
        return operator bool();
    }

    template <typename T>
    Result<T>::operator bool() const {
        return value_.presented();
    }

    template <typename T>
    const T & Result<T>::value() const {
        return operator*();
    }

    template <typename T>
    const Ptr<Error> & Result<T>::error() const {
        RHETORIC_ASSERT(error_ != nullptr);
        return error_;
    }

    template <typename T>
    const T * Result<T>::operator->() const {
        return value_.operator->();
    }

    template <typename T>
    const T & Result<T>::operator*() const {
        return *operator->();
    }

    template <typename T>
    T Result<T>::Recover(const T & recovery_value) const {
        if (!succeeded()) {
            return recovery_value;
        }
        return value();
    }

    template <typename T>
    Result<T> Success(const T & value) {
        return Result<T>(value, ResultSuccessTag());
    }

    template <typename T>
    ResultFailure Failure(const Result<T> & result) {
        return ResultFailure { result.error() };
    }

}
