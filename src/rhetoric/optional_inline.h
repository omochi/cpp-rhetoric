namespace rhetoric {
    template <typename T>
    Optional<T>::Optional():Optional(None()){}
    
    template <typename T>
    Optional<T>::Optional(const T & value, OptionalSomeTag tag):
    value_(new T(value))
    {
        RHETORIC_UNUSED(tag);
    }

    template <typename T>
    Optional<T>::Optional(const None & none):
    value_(nullptr)
    {}

    template <typename T>
    Optional<T>::Optional(const Optional<T> & other):
    value_(nullptr)
    {
        if (other) {
            value_ = new T(*other);
        }
    }

    template <typename T>
    Optional<T> & Optional<T>::operator=(const Optional<T> & other)
    {
        Optional<T> temp(other);
        Swap(temp);
        return *this;
    }

    template <typename T>
    template <typename U>
    Optional<T>::Optional(const Optional<U> & other,
                          typename std::enable_if<std::is_convertible<U, T>::value>::type * enabler):
    value_(nullptr)
    {
        if (other) {
            value_ = new T(static_cast<T>(*other));
        }
    }

    template <typename T>
    Optional<T>::~Optional()
    {
        if (value_) {
            delete value_;
            value_ = nullptr;
        }
    }

    template <typename T>
    void Optional<T>::Swap(Optional<T> & other) {
        std::swap(value_, other.value_);
    }

    template <typename T>
    bool Optional<T>::presented() const {
        return operator bool();
    }

    template <typename T>
    Optional<T>::operator bool() const {
        return value_ != nullptr;
    }

    template <typename T>
    const T & Optional<T>::value() const {
        return operator*();
    }

    template <typename T>
    const T * Optional<T>::operator->() const {
        RHETORIC_ASSERT(value_ != nullptr);
        return value_;
    }

    template <typename T>
    const T & Optional<T>::operator*() const {
        return *operator->();
    }

    template <typename T>
    bool Optional<T>::operator==(const Optional<T> & other) const {
        if (*this) {
            if (other) {
                return *value_ == *other.value_;
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
    Optional<T> Some(const T & value) {
        return Optional<T>(value, OptionalSomeTag());
    }
    
}
