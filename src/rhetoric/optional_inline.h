namespace rhetoric {
    template <typename T>
    Optional<T>::Optional():Optional(None())
    {}
    
    template <typename T>
    Optional<T>::Optional(const None &):
    either_(EitherCase<NoneTag>(None()))
    {}
    
    template <typename T>
    Optional<T>::Optional(const Either2CaseWrapper<SomeTag, T> & value):
    either_(value)
    {}
    
    template <typename T>
    Optional<T>::Optional(const Optional<T> & other):
    either_(other.either_)
    {}

    template <typename T>
    Optional<T> & Optional<T>::operator=(const Optional<T> & other)
    {
        either_ = other.either_;
        return *this;
    }

    template <typename T>
    template <typename U>
    Optional<T>::Optional(const Optional<U> & other,
                          typename std::enable_if<std::is_convertible<U, T>::value>::type *):
    either_(other.presented() ?
            Either2<None, T>(EitherCase<SomeTag>(static_cast<T>(other.value()))) :
            Either2<None, T>(EitherCase<NoneTag>(None()))
            )
    {}

    template <typename T>
    Optional<T>::~Optional()
    {}

    template <typename T>
    bool Optional<T>::presented() const {
        return operator bool();
    }

    template <typename T>
    Optional<T>::operator bool() const {
        return either_.tag() == SomeTag;
    }

    template <typename T>
    const T & Optional<T>::value() const {
        return operator*();
    }

    template <typename T>
    const T * Optional<T>::operator->() const {
        return &operator*();
    }

    template <typename T>
    const T & Optional<T>::operator*() const {
        return either_.AsCase1();
    }

    template <typename T>
    bool Optional<T>::operator==(const Optional<T> & other) const {
        if (presented()) {
            if (other) {
                return value() == other.value();
            } else {
                return false;
            }
        } else {
            if (other) {
                return false;
            } else {
                return true;
            }
        }
    }

    template <typename T>
    T Optional<T>::GetOr(const T & default_value) const {
        if (presented()) {
            return value();
        }
        return default_value;
    }
    
    template <typename T>
    Optional<T> Some(const T & value) {
        return Optional<T>(EitherCase<SomeTag>(value));
    }
    
}
