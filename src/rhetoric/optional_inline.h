namespace rhetoric {
    template <typename T>
    Optional<T>::Optional():Optional(None())
    {}
    
    template <typename T>
    Optional<T>::Optional(const None &):
    either_(EitherCase<0>(None()))
    {}

    template <typename T>
    Optional<T>::Optional(const T & value, OptionalSomeTag):
    either_(EitherCase<1>(value))
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
            Either2<None, T>(EitherCase<1>(static_cast<T>(other.value()))) :
            Either2<None, T>(EitherCase<0>(None()))
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
        return either_.tag() == Either2<None, T>::Tag::Case1;
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
        return Optional<T>(value, OptionalSomeTag());
    }
    
}
