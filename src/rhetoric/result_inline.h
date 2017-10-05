namespace rhetoric {
    template <typename T>
    Result<T>::Result():
    either_(EitherCase<OkTag>(T()))
    {}

    template <typename T>
    Result<T>::Result(const Ptr<Error> & error):
    either_(EitherCase<ErrorTag>(error))
    {
        RHETORIC_ASSERT(error != nullptr);
    }
    
    template <typename T>
    template <typename E>
    Result<T>::Result(const E & error,
                      std::enable_if_t<std::is_convertible<E, Ptr<Error>>::value> *):
    Result(static_cast<Ptr<Error>>(error))
    {}
    
    template <typename T>
    Result<T>::Result(const Either2CaseWrapper<OkTag, T> & value):
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
    either_(other.ok() ?
            Either2<Ptr<Error>, T>(EitherCase<OkTag>(static_cast<T>(other.value()))) :
            Either2<Ptr<Error>, T>(EitherCase<ErrorTag>(other.error()))
            )
    {}

    template <typename T>
    Result<T>::~Result()
    {}

    template <typename T>
    bool Result<T>::ok() const {
        return operator bool();
    }

    template <typename T>
    Result<T>::operator bool() const {
        return either_.tag() == OkTag;
    }

    template <typename T>
    const T & Result<T>::value() const {
        if (!ok()) {
            RHETORIC_FATAL(Format("Result is error: %s", either_.AsCase0()->ToString().c_str()));
        }
        return either_.AsCase1();
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
        return value();
    }

    template <typename T>
    T Result<T>::Recover(const T & recovery_value) const {
        if (ok()) {
            return value();
        }
        return recovery_value;
    }

    template <typename T>
    Result<T> Ok(const T & value) {
        return Result<T>(EitherCase<OkTag>(value));
    }
}
