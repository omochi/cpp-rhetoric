namespace rhetoric {
    template <int C, typename T>
    EitherCaseWrapper<C, T> EitherCase(const T & value) {
        return EitherCaseWrapper<C, T>(value);
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::
    Either2(const EitherCaseWrapper<0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1>
    Either2<T0, T1>::
    Either2(const EitherCaseWrapper<1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1>
    Either2<T0, T1>::
    Either2(const Either2<T0, T1> & other) {
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
    Either2<T0, T1>::
    Either2(
        const Either2<U0, U1> & other,
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
    Either2<T0, T1> & 
    Either2<T0, T1>::
    operator= (const Either2<T0, T1> & other) {
        Deinit();
        
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
    Either2<T0, T1>::~Either2() {
        Deinit();
    }
    
    template <typename T0, typename T1>
    typename Either2<T0, T1>::Tag 
    Either2<T0, T1>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1>
    const T0 & 
    Either2<T0, T1>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1>
    const T1 & 
    Either2<T0, T1>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::
    Storage::Storage() {}

    template <typename T0, typename T1>
    Either2<T0, T1>::
    Storage::~Storage() {}
    
    template <typename T0, typename T1>
    void
    Either2<T0, T1>::
    InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Tag::Case0;
    }
    
    template <typename T0, typename T1>
    void
    Either2<T0, T1>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Tag::Case1;
    }
    
    template <typename T0, typename T1>
    void 
    Either2<T0, T1>::
    Deinit() {
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
    
    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const EitherCaseWrapper<0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const EitherCaseWrapper<1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const EitherCaseWrapper<2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const Either3<T0, T1, T2> & other) {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Tag::Case2:
                InitValue2(other.AsCase2());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2>
    template <typename U0, typename U1, typename U2>
    Either3<T0, T1, T2>::
    Either3(
        const Either3<U0, U1, U2> & other,
        typename std::enable_if<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value
        >::type *)
    {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2> & 
    Either3<T0, T1, T2>::
    operator= (const Either3<T0, T1, T2> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Tag::Case2:
                InitValue2(other.AsCase2());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::~Either3() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2>
    typename Either3<T0, T1, T2>::Tag 
    Either3<T0, T1, T2>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2>
    const T0 & 
    Either3<T0, T1, T2>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2>
    const T1 & 
    Either3<T0, T1, T2>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2>
    const T2 & 
    Either3<T0, T1, T2>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Storage::Storage() {}

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Storage::~Storage() {}
    
    template <typename T0, typename T1, typename T2>
    void
    Either3<T0, T1, T2>::
    InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2>
    void
    Either3<T0, T1, T2>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2>
    void
    Either3<T0, T1, T2>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2>
    void 
    Either3<T0, T1, T2>::
    Deinit() {
        switch (tag_) {
            case Tag::Case0:
                storage_.value0.~T0();
                break;
            case Tag::Case1:
                storage_.value1.~T1();
                break;
            case Tag::Case2:
                storage_.value2.~T2();
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const EitherCaseWrapper<0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const EitherCaseWrapper<1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const EitherCaseWrapper<2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const EitherCaseWrapper<3, T3> & value) {
        InitValue3(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const Either4<T0, T1, T2, T3> & other) {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Tag::Case3:
                InitValue3(other.AsCase3());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    template <typename U0, typename U1, typename U2, typename U3>
    Either4<T0, T1, T2, T3>::
    Either4(
        const Either4<U0, U1, U2, U3> & other,
        typename std::enable_if<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value &&
            std::is_convertible<U3, T3>::value
        >::type *)
    {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
            case Tag::Case3:
                InitValue3(static_cast<T3>(other.AsCase3()));
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3> & 
    Either4<T0, T1, T2, T3>::
    operator= (const Either4<T0, T1, T2, T3> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Tag::Case3:
                InitValue3(other.AsCase3());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::~Either4() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    typename Either4<T0, T1, T2, T3>::Tag 
    Either4<T0, T1, T2, T3>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T0 & 
    Either4<T0, T1, T2, T3>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T1 & 
    Either4<T0, T1, T2, T3>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T2 & 
    Either4<T0, T1, T2, T3>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T3 & 
    Either4<T0, T1, T2, T3>::
    AsCase3() const {
        RHETORIC_ASSERT(tag_ == Tag::Case3);
        return storage_.value3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Storage::Storage() {}

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Storage::~Storage() {}
    
    template <typename T0, typename T1, typename T2, typename T3>
    void
    Either4<T0, T1, T2, T3>::
    InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void
    Either4<T0, T1, T2, T3>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void
    Either4<T0, T1, T2, T3>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void
    Either4<T0, T1, T2, T3>::
    InitValue3(const T3 & value) {
        new (&storage_.value3) T3(value);
        tag_ = Tag::Case3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void 
    Either4<T0, T1, T2, T3>::
    Deinit() {
        switch (tag_) {
            case Tag::Case0:
                storage_.value0.~T0();
                break;
            case Tag::Case1:
                storage_.value1.~T1();
                break;
            case Tag::Case2:
                storage_.value2.~T2();
                break;
            case Tag::Case3:
                storage_.value3.~T3();
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const EitherCaseWrapper<0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const EitherCaseWrapper<1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const EitherCaseWrapper<2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const EitherCaseWrapper<3, T3> & value) {
        InitValue3(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const EitherCaseWrapper<4, T4> & value) {
        InitValue4(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const Either5<T0, T1, T2, T3, T4> & other) {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Tag::Case4:
                InitValue4(other.AsCase4());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    template <typename U0, typename U1, typename U2, typename U3, typename U4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(
        const Either5<U0, U1, U2, U3, U4> & other,
        typename std::enable_if<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value &&
            std::is_convertible<U3, T3>::value &&
            std::is_convertible<U4, T4>::value
        >::type *)
    {
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
            case Tag::Case3:
                InitValue3(static_cast<T3>(other.AsCase3()));
                break;
            case Tag::Case4:
                InitValue4(static_cast<T4>(other.AsCase4()));
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4> & 
    Either5<T0, T1, T2, T3, T4>::
    operator= (const Either5<T0, T1, T2, T3, T4> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Tag::Case4:
                InitValue4(other.AsCase4());
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::~Either5() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    typename Either5<T0, T1, T2, T3, T4>::Tag 
    Either5<T0, T1, T2, T3, T4>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T0 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T1 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T2 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T3 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase3() const {
        RHETORIC_ASSERT(tag_ == Tag::Case3);
        return storage_.value3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T4 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase4() const {
        RHETORIC_ASSERT(tag_ == Tag::Case4);
        return storage_.value4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Storage::Storage() {}

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Storage::~Storage() {}
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue3(const T3 & value) {
        new (&storage_.value3) T3(value);
        tag_ = Tag::Case3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue4(const T4 & value) {
        new (&storage_.value4) T4(value);
        tag_ = Tag::Case4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void 
    Either5<T0, T1, T2, T3, T4>::
    Deinit() {
        switch (tag_) {
            case Tag::Case0:
                storage_.value0.~T0();
                break;
            case Tag::Case1:
                storage_.value1.~T1();
                break;
            case Tag::Case2:
                storage_.value2.~T2();
                break;
            case Tag::Case3:
                storage_.value3.~T3();
                break;
            case Tag::Case4:
                storage_.value4.~T4();
                break;
        }
        RHETORIC_FATAL("never");
    }
    
    template <int C, typename T>
    EitherCaseWrapper<C, T>::EitherCaseWrapper(const T & value):
    value(value)
    {}
    
}
