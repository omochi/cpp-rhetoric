namespace rhetoric {
    template <typename T>
    Option<T>::Option():Option(None())
    {}
    
    template <typename T>
    Option<T>::Option(const None &):
    either_(EitherCase<NoneTag>(None()))
    {}
    
    template <typename T>
    Option<T>::Option(const Either2CaseWrapper<SomeTag, T> & value):
    either_(value)
    {}
    
    template <typename T>
    Option<T>::Option(const Option<T> & other):
    either_(other.either_)
    {}

    template <typename T>
    Option<T> & Option<T>::operator=(const Option<T> & other)
    {
        either_ = other.either_;
        return *this;
    }

    template <typename T>
    template <typename U>
    Option<T>::Option(const Option<U> & other,
                          typename std::enable_if<std::is_convertible<U, T>::value>::type *):
    either_(other.presented() ?
            Either2<None, T>(EitherCase<SomeTag>(static_cast<T>(other.value()))) :
            Either2<None, T>(EitherCase<NoneTag>(None()))
            )
    {}

    template <typename T>
    Option<T>::~Option()
    {}

    template <typename T>
    bool Option<T>::presented() const {
        return operator bool();
    }

    template <typename T>
    Option<T>::operator bool() const {
        return either_.tag() == SomeTag;
    }

    template <typename T>
    const T & Option<T>::value() const {
        return operator*();
    }

    template <typename T>
    const T * Option<T>::operator->() const {
        return &operator*();
    }

    template <typename T>
    const T & Option<T>::operator*() const {
        return either_.AsCase1();
    }

    template <typename T>
    bool Option<T>::operator==(const Option<T> & other) const {
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
    T Option<T>::GetOr(const T & default_value) const {
        if (presented()) {
            return value();
        }
        return default_value;
    }
    
    template <typename T>
    Option<T> Some(const T & value) {
        return Option<T>(EitherCase<SomeTag>(value));
    }
    
}
