namespace rhetoric {
    template <int C, typename T>
    EitherCaseWrapper<C, T> EitherCase(const T & value) {
        return EitherCaseWrapper<C, T>(value);
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::Either2(const EitherCaseWrapper<0, T0> & value) {
        InitValue0(value.value);
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::Either2(const EitherCaseWrapper<1, T1> & value) {
        InitValue1(value.value);
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::Either2(const Either2<T0, T1> & other) {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Tag::Case1:
                InitValue1(other.AsCase1());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1>
    template <typename U0, typename U1>
    Either2<T0, T1>::Either2(const Either2<U0, U1> & other,
            typename std::enable_if<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value
            >::type *)
    {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1> & Either2<T0, T1>::operator= (const Either2<T0, T1> & other) {
        Deinit();
        
        switch (other.tag()) {
            case 0:
                InitValue0(other.value0());
                break;
            case 1:
                InitValue1(other.value1());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::~Either2() {
        Deinit();
    }
    
    template <typename T0, typename T1>
    typename Either2<T0, T1>::Tag Either2<T0, T1>::tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1>
    const T0 & Either2<T0, T1>::AsCase0() const {
        RHETORIC_ASSERT(tag_ == Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1>
    const T1 & Either2<T0, T1>::AsCase1() const {
        RHETORIC_ASSERT(tag_ == Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::Storage::Storage() {}

    template <typename T0, typename T1>
    Either2<T0, T1>::Storage::~Storage() {}
    
    template <typename T0, typename T1>
    void Either2<T0, T1>::InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Tag::Case0;
    }
    
    template <typename T0, typename T1>
    void Either2<T0, T1>::InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Tag::Case1;
    }
    
    template <typename T0, typename T1>
    void Either2<T0, T1>::Deinit() {
        switch (tag_) {
            case Tag::Case0:
                storage_.value0.~T0();
                break;
            case Tag::Case1:
                storage_.value1.~T1();
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <int C, typename T>
    EitherCaseWrapper<C, T>::EitherCaseWrapper(const T & value):
    value(value)
    {}
    
}
