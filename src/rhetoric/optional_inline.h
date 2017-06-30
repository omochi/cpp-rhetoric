namespace rhetoric {
    template <typename T>
    Optional<T>::Optional()
    {
        InitNone();
    }
    
    template <typename T>
    Optional<T>::Optional(const T & value, OptionalSomeTag)
    {
        InitValue(value);
    }

    template <typename T>
    Optional<T>::Optional(const None &)
    {
        InitNone();
    }

    template <typename T>
    Optional<T>::Optional(const Optional<T> & other)
    {
        if (other) {
            InitValue(other.value());
        } else {
            InitNone();
        }
    }

    template <typename T>
    Optional<T> & Optional<T>::operator=(const Optional<T> & other)
    {
        DeinitStorage();
        
        if (other) {
            InitValue(other.value());
        } else {
            InitNone();
        }
        return *this;
    }

    template <typename T>
    template <typename U>
    Optional<T>::Optional(const Optional<U> & other,
                          typename std::enable_if<std::is_convertible<U, T>::value>::type *)
    {
        if (other) {
            InitValue(static_cast<T>(other.value()));
        } else {
            InitNone();
        }
    }

    template <typename T>
    Optional<T>::~Optional()
    {
        DeinitStorage();
    }

    template <typename T>
    bool Optional<T>::presented() const {
        return operator bool();
    }

    template <typename T>
    Optional<T>::operator bool() const {
        return presented_;
    }

    template <typename T>
    const T & Optional<T>::value() const {
        return operator*();
    }

    template <typename T>
    const T * Optional<T>::operator->() const {
        RHETORIC_ASSERT(presented());
        return &storage_.value_;
    }

    template <typename T>
    const T & Optional<T>::operator*() const {
        return *operator->();
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
    T Optional<T>::GetOr(const T & alt) const {
        if (*this) {
            return value();
        }
        return alt;
    }
    
    template <typename T>
    Optional<T>::Storage::Storage()
    {}
    
    template <typename T>
    Optional<T>::Storage::~Storage()
    {}
    
    template <typename T>
    void Optional<T>::InitNone() {
        presented_ = false;
    }
    
    template <typename T>
    void Optional<T>::InitValue(const T & value) {
        new (&storage_.value_) T (value);
        presented_ = true;
    }
    
    template <typename T>
    void Optional<T>::DeinitStorage() {
        if (presented()) {
            storage_.value_.~T();
            presented_ = false;
        }
    }

    template <typename T>
    Optional<T> Some(const T & value) {
        return Optional<T>(value, OptionalSomeTag());
    }
    
}
