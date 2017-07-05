namespace rhetoric {
    template <typename T>
    Result<T>::Result():
    either_(Either2Case<SuccessTag>(T()))
    {}

    template <typename T>
    Result<T>::Result(const ResultFailure & failure):
    either_(Either2Case<FailureTag>(failure.error))
    {
        RHETORIC_ASSERT(failure.error != nullptr);
    }
    
    template <typename T>
    Result<T>::Result(const Either2CaseWrapper<SuccessTag, T> & value):
    either_(value)
    {}

    template <typename T>
    Result<T>::Result(const Result<T> & other):
    either_(other.either_)
    {}

    template <typename T>
    Result<T> & Result<T>::operator=(const Result<T> & other) {
        either_ = other.either_;
        return *this;
    }

    template <typename T>
    template <typename U>
    Result<T>::Result(const Result<U> & other,
                      typename std::enable_if_t<std::is_convertible<U, T>::value> *):
    either_(other.succeeded() ?
            Either2<Ptr<Error>, T>(Either2Case<SuccessTag>(static_cast<T>(other.value()))) :
            Either2<Ptr<Error>, T>(Either2Case<FailureTag>(other.error()))
            )
    {}

    template <typename T>
    Result<T>::~Result()
    {}

    template <typename T>
    bool Result<T>::succeeded() const {
        return operator bool();
    }

    template <typename T>
    Result<T>::operator bool() const {
        return either_.tag() == SuccessTag;
    }

    template <typename T>
    const T & Result<T>::value() const {
        return operator*();
    }

    template <typename T>
    const Ptr<Error> & Result<T>::error() const {
        return either_.AsCase0();
    }

    template <typename T>
    const T * Result<T>::operator->() const {
        return &operator*();
    }

    template <typename T>
    const T & Result<T>::operator*() const {
        return either_.AsCase1();
    }

    template <typename T>
    T Result<T>::Recover(const T & recovery_value) const {
        if (succeeded()) {
            return value();
        }
        return recovery_value;
    }

    template <typename T>
    Result<T> Success(const T & value) {
        return Result<T>(Either2Case<SuccessTag>(value));
    }

    template <typename T>
    ResultFailure Failure(const Result<T> & result) {
        return ResultFailure { result.error() };
    }

}
