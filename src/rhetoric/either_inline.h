namespace rhetoric {
    template <Either2Tag G, typename T>
    Either2CaseWrapper<G, T>

    EitherCase(const T & value) {
        return Either2CaseWrapper<G, T>(value);
    }

    template <typename T0, typename T1>
    Either2<T0, T1>::
    Either2(const Either2CaseWrapper<Either2Tag::Case0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1>
    Either2<T0, T1>::
    Either2(const Either2CaseWrapper<Either2Tag::Case1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1>
    Either2<T0, T1>::
    Either2(const Either2<T0, T1> & other) {
        switch (other.tag()) {
            case Either2Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either2Tag::Case1:
                InitValue1(other.AsCase1());
                break;
        }
    }
    
    template <typename T0, typename T1>
    template <typename U0, typename U1>
    Either2<T0, T1>::
    Either2(
        const Either2<U0, U1> & other,
        std::enable_if_t<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value
        > *)
    {
        switch (other.tag()) {
            case Either2Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Either2Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
        }
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1> & 
    Either2<T0, T1>::
    operator= (const Either2<T0, T1> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Either2Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either2Tag::Case1:
                InitValue1(other.AsCase1());
                break;
        }

        return *this;
    }
    
    template <typename T0, typename T1>
    Either2<T0, T1>::~Either2() {
        Deinit();
    }
    
    template <typename T0, typename T1>
    Either2Tag
    Either2<T0, T1>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1>
    const T0 & 
    Either2<T0, T1>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Either2Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1>
    const T1 & 
    Either2<T0, T1>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Either2Tag::Case1);
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
        tag_ = Either2Tag::Case0;
    }
    
    template <typename T0, typename T1>
    void
    Either2<T0, T1>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Either2Tag::Case1;
    }
    
    template <typename T0, typename T1>
    void 
    Either2<T0, T1>::
    Deinit() {
        switch (tag_) {
            case Either2Tag::Case0:
                storage_.value0.~T0();
                break;
            case Either2Tag::Case1:
                storage_.value1.~T1();
                break;
        }
    }
    
    template <Either2Tag G, typename T>
    Either2CaseWrapper<G, T>::Either2CaseWrapper(const T & value):
    value(value)
    {}

    template <Either3Tag G, typename T>
    Either3CaseWrapper<G, T>

    EitherCase(const T & value) {
        return Either3CaseWrapper<G, T>(value);
    }

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const Either3CaseWrapper<Either3Tag::Case0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const Either3CaseWrapper<Either3Tag::Case1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const Either3CaseWrapper<Either3Tag::Case2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::
    Either3(const Either3<T0, T1, T2> & other) {
        switch (other.tag()) {
            case Either3Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either3Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either3Tag::Case2:
                InitValue2(other.AsCase2());
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2>
    template <typename U0, typename U1, typename U2>
    Either3<T0, T1, T2>::
    Either3(
        const Either3<U0, U1, U2> & other,
        std::enable_if_t<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value
        > *)
    {
        switch (other.tag()) {
            case Either3Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Either3Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Either3Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2> & 
    Either3<T0, T1, T2>::
    operator= (const Either3<T0, T1, T2> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Either3Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either3Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either3Tag::Case2:
                InitValue2(other.AsCase2());
                break;
        }

        return *this;
    }
    
    template <typename T0, typename T1, typename T2>
    Either3<T0, T1, T2>::~Either3() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2>
    Either3Tag
    Either3<T0, T1, T2>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2>
    const T0 & 
    Either3<T0, T1, T2>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Either3Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2>
    const T1 & 
    Either3<T0, T1, T2>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Either3Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2>
    const T2 & 
    Either3<T0, T1, T2>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Either3Tag::Case2);
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
        tag_ = Either3Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2>
    void
    Either3<T0, T1, T2>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Either3Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2>
    void
    Either3<T0, T1, T2>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Either3Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2>
    void 
    Either3<T0, T1, T2>::
    Deinit() {
        switch (tag_) {
            case Either3Tag::Case0:
                storage_.value0.~T0();
                break;
            case Either3Tag::Case1:
                storage_.value1.~T1();
                break;
            case Either3Tag::Case2:
                storage_.value2.~T2();
                break;
        }
    }
    
    template <Either3Tag G, typename T>
    Either3CaseWrapper<G, T>::Either3CaseWrapper(const T & value):
    value(value)
    {}

    template <Either4Tag G, typename T>
    Either4CaseWrapper<G, T>

    EitherCase(const T & value) {
        return Either4CaseWrapper<G, T>(value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const Either4CaseWrapper<Either4Tag::Case0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const Either4CaseWrapper<Either4Tag::Case1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const Either4CaseWrapper<Either4Tag::Case2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const Either4CaseWrapper<Either4Tag::Case3, T3> & value) {
        InitValue3(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::
    Either4(const Either4<T0, T1, T2, T3> & other) {
        switch (other.tag()) {
            case Either4Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either4Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either4Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either4Tag::Case3:
                InitValue3(other.AsCase3());
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    template <typename U0, typename U1, typename U2, typename U3>
    Either4<T0, T1, T2, T3>::
    Either4(
        const Either4<U0, U1, U2, U3> & other,
        std::enable_if_t<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value &&
            std::is_convertible<U3, T3>::value
        > *)
    {
        switch (other.tag()) {
            case Either4Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Either4Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Either4Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
            case Either4Tag::Case3:
                InitValue3(static_cast<T3>(other.AsCase3()));
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3> & 
    Either4<T0, T1, T2, T3>::
    operator= (const Either4<T0, T1, T2, T3> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Either4Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either4Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either4Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either4Tag::Case3:
                InitValue3(other.AsCase3());
                break;
        }

        return *this;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    Either4<T0, T1, T2, T3>::~Either4() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    Either4Tag
    Either4<T0, T1, T2, T3>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T0 & 
    Either4<T0, T1, T2, T3>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Either4Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T1 & 
    Either4<T0, T1, T2, T3>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Either4Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T2 & 
    Either4<T0, T1, T2, T3>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Either4Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    const T3 & 
    Either4<T0, T1, T2, T3>::
    AsCase3() const {
        RHETORIC_ASSERT(tag_ == Either4Tag::Case3);
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
        tag_ = Either4Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void
    Either4<T0, T1, T2, T3>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Either4Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void
    Either4<T0, T1, T2, T3>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Either4Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void
    Either4<T0, T1, T2, T3>::
    InitValue3(const T3 & value) {
        new (&storage_.value3) T3(value);
        tag_ = Either4Tag::Case3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3>
    void 
    Either4<T0, T1, T2, T3>::
    Deinit() {
        switch (tag_) {
            case Either4Tag::Case0:
                storage_.value0.~T0();
                break;
            case Either4Tag::Case1:
                storage_.value1.~T1();
                break;
            case Either4Tag::Case2:
                storage_.value2.~T2();
                break;
            case Either4Tag::Case3:
                storage_.value3.~T3();
                break;
        }
    }
    
    template <Either4Tag G, typename T>
    Either4CaseWrapper<G, T>::Either4CaseWrapper(const T & value):
    value(value)
    {}

    template <Either5Tag G, typename T>
    Either5CaseWrapper<G, T>

    EitherCase(const T & value) {
        return Either5CaseWrapper<G, T>(value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const Either5CaseWrapper<Either5Tag::Case0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const Either5CaseWrapper<Either5Tag::Case1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const Either5CaseWrapper<Either5Tag::Case2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const Either5CaseWrapper<Either5Tag::Case3, T3> & value) {
        InitValue3(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const Either5CaseWrapper<Either5Tag::Case4, T4> & value) {
        InitValue4(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(const Either5<T0, T1, T2, T3, T4> & other) {
        switch (other.tag()) {
            case Either5Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either5Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either5Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either5Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either5Tag::Case4:
                InitValue4(other.AsCase4());
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    template <typename U0, typename U1, typename U2, typename U3, typename U4>
    Either5<T0, T1, T2, T3, T4>::
    Either5(
        const Either5<U0, U1, U2, U3, U4> & other,
        std::enable_if_t<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value &&
            std::is_convertible<U3, T3>::value &&
            std::is_convertible<U4, T4>::value
        > *)
    {
        switch (other.tag()) {
            case Either5Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Either5Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Either5Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
            case Either5Tag::Case3:
                InitValue3(static_cast<T3>(other.AsCase3()));
                break;
            case Either5Tag::Case4:
                InitValue4(static_cast<T4>(other.AsCase4()));
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4> & 
    Either5<T0, T1, T2, T3, T4>::
    operator= (const Either5<T0, T1, T2, T3, T4> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Either5Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either5Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either5Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either5Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either5Tag::Case4:
                InitValue4(other.AsCase4());
                break;
        }

        return *this;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5<T0, T1, T2, T3, T4>::~Either5() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    Either5Tag
    Either5<T0, T1, T2, T3, T4>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T0 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Either5Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T1 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Either5Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T2 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Either5Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T3 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase3() const {
        RHETORIC_ASSERT(tag_ == Either5Tag::Case3);
        return storage_.value3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    const T4 & 
    Either5<T0, T1, T2, T3, T4>::
    AsCase4() const {
        RHETORIC_ASSERT(tag_ == Either5Tag::Case4);
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
        tag_ = Either5Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Either5Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Either5Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue3(const T3 & value) {
        new (&storage_.value3) T3(value);
        tag_ = Either5Tag::Case3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void
    Either5<T0, T1, T2, T3, T4>::
    InitValue4(const T4 & value) {
        new (&storage_.value4) T4(value);
        tag_ = Either5Tag::Case4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void 
    Either5<T0, T1, T2, T3, T4>::
    Deinit() {
        switch (tag_) {
            case Either5Tag::Case0:
                storage_.value0.~T0();
                break;
            case Either5Tag::Case1:
                storage_.value1.~T1();
                break;
            case Either5Tag::Case2:
                storage_.value2.~T2();
                break;
            case Either5Tag::Case3:
                storage_.value3.~T3();
                break;
            case Either5Tag::Case4:
                storage_.value4.~T4();
                break;
        }
    }
    
    template <Either5Tag G, typename T>
    Either5CaseWrapper<G, T>::Either5CaseWrapper(const T & value):
    value(value)
    {}

    template <Either6Tag G, typename T>
    Either6CaseWrapper<G, T>

    EitherCase(const T & value) {
        return Either6CaseWrapper<G, T>(value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(const Either6CaseWrapper<Either6Tag::Case0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(const Either6CaseWrapper<Either6Tag::Case1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(const Either6CaseWrapper<Either6Tag::Case2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(const Either6CaseWrapper<Either6Tag::Case3, T3> & value) {
        InitValue3(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(const Either6CaseWrapper<Either6Tag::Case4, T4> & value) {
        InitValue4(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(const Either6CaseWrapper<Either6Tag::Case5, T5> & value) {
        InitValue5(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(const Either6<T0, T1, T2, T3, T4, T5> & other) {
        switch (other.tag()) {
            case Either6Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either6Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either6Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either6Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either6Tag::Case4:
                InitValue4(other.AsCase4());
                break;
            case Either6Tag::Case5:
                InitValue5(other.AsCase5());
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Either6(
        const Either6<U0, U1, U2, U3, U4, U5> & other,
        std::enable_if_t<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value &&
            std::is_convertible<U3, T3>::value &&
            std::is_convertible<U4, T4>::value &&
            std::is_convertible<U5, T5>::value
        > *)
    {
        switch (other.tag()) {
            case Either6Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Either6Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Either6Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
            case Either6Tag::Case3:
                InitValue3(static_cast<T3>(other.AsCase3()));
                break;
            case Either6Tag::Case4:
                InitValue4(static_cast<T4>(other.AsCase4()));
                break;
            case Either6Tag::Case5:
                InitValue5(static_cast<T5>(other.AsCase5()));
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5> & 
    Either6<T0, T1, T2, T3, T4, T5>::
    operator= (const Either6<T0, T1, T2, T3, T4, T5> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Either6Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either6Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either6Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either6Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either6Tag::Case4:
                InitValue4(other.AsCase4());
                break;
            case Either6Tag::Case5:
                InitValue5(other.AsCase5());
                break;
        }

        return *this;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::~Either6() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6Tag
    Either6<T0, T1, T2, T3, T4, T5>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    const T0 & 
    Either6<T0, T1, T2, T3, T4, T5>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Either6Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    const T1 & 
    Either6<T0, T1, T2, T3, T4, T5>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Either6Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    const T2 & 
    Either6<T0, T1, T2, T3, T4, T5>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Either6Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    const T3 & 
    Either6<T0, T1, T2, T3, T4, T5>::
    AsCase3() const {
        RHETORIC_ASSERT(tag_ == Either6Tag::Case3);
        return storage_.value3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    const T4 & 
    Either6<T0, T1, T2, T3, T4, T5>::
    AsCase4() const {
        RHETORIC_ASSERT(tag_ == Either6Tag::Case4);
        return storage_.value4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    const T5 & 
    Either6<T0, T1, T2, T3, T4, T5>::
    AsCase5() const {
        RHETORIC_ASSERT(tag_ == Either6Tag::Case5);
        return storage_.value5;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Storage::Storage() {}

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    Either6<T0, T1, T2, T3, T4, T5>::
    Storage::~Storage() {}
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void
    Either6<T0, T1, T2, T3, T4, T5>::
    InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Either6Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void
    Either6<T0, T1, T2, T3, T4, T5>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Either6Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void
    Either6<T0, T1, T2, T3, T4, T5>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Either6Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void
    Either6<T0, T1, T2, T3, T4, T5>::
    InitValue3(const T3 & value) {
        new (&storage_.value3) T3(value);
        tag_ = Either6Tag::Case3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void
    Either6<T0, T1, T2, T3, T4, T5>::
    InitValue4(const T4 & value) {
        new (&storage_.value4) T4(value);
        tag_ = Either6Tag::Case4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void
    Either6<T0, T1, T2, T3, T4, T5>::
    InitValue5(const T5 & value) {
        new (&storage_.value5) T5(value);
        tag_ = Either6Tag::Case5;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void 
    Either6<T0, T1, T2, T3, T4, T5>::
    Deinit() {
        switch (tag_) {
            case Either6Tag::Case0:
                storage_.value0.~T0();
                break;
            case Either6Tag::Case1:
                storage_.value1.~T1();
                break;
            case Either6Tag::Case2:
                storage_.value2.~T2();
                break;
            case Either6Tag::Case3:
                storage_.value3.~T3();
                break;
            case Either6Tag::Case4:
                storage_.value4.~T4();
                break;
            case Either6Tag::Case5:
                storage_.value5.~T5();
                break;
        }
    }
    
    template <Either6Tag G, typename T>
    Either6CaseWrapper<G, T>::Either6CaseWrapper(const T & value):
    value(value)
    {}

    template <Either7Tag G, typename T>
    Either7CaseWrapper<G, T>

    EitherCase(const T & value) {
        return Either7CaseWrapper<G, T>(value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7CaseWrapper<Either7Tag::Case0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7CaseWrapper<Either7Tag::Case1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7CaseWrapper<Either7Tag::Case2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7CaseWrapper<Either7Tag::Case3, T3> & value) {
        InitValue3(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7CaseWrapper<Either7Tag::Case4, T4> & value) {
        InitValue4(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7CaseWrapper<Either7Tag::Case5, T5> & value) {
        InitValue5(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7CaseWrapper<Either7Tag::Case6, T6> & value) {
        InitValue6(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(const Either7<T0, T1, T2, T3, T4, T5, T6> & other) {
        switch (other.tag()) {
            case Either7Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either7Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either7Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either7Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either7Tag::Case4:
                InitValue4(other.AsCase4());
                break;
            case Either7Tag::Case5:
                InitValue5(other.AsCase5());
                break;
            case Either7Tag::Case6:
                InitValue6(other.AsCase6());
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Either7(
        const Either7<U0, U1, U2, U3, U4, U5, U6> & other,
        std::enable_if_t<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value &&
            std::is_convertible<U3, T3>::value &&
            std::is_convertible<U4, T4>::value &&
            std::is_convertible<U5, T5>::value &&
            std::is_convertible<U6, T6>::value
        > *)
    {
        switch (other.tag()) {
            case Either7Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Either7Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Either7Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
            case Either7Tag::Case3:
                InitValue3(static_cast<T3>(other.AsCase3()));
                break;
            case Either7Tag::Case4:
                InitValue4(static_cast<T4>(other.AsCase4()));
                break;
            case Either7Tag::Case5:
                InitValue5(static_cast<T5>(other.AsCase5()));
                break;
            case Either7Tag::Case6:
                InitValue6(static_cast<T6>(other.AsCase6()));
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6> & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    operator= (const Either7<T0, T1, T2, T3, T4, T5, T6> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Either7Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either7Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either7Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either7Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either7Tag::Case4:
                InitValue4(other.AsCase4());
                break;
            case Either7Tag::Case5:
                InitValue5(other.AsCase5());
                break;
            case Either7Tag::Case6:
                InitValue6(other.AsCase6());
                break;
        }

        return *this;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::~Either7() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7Tag
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    const T0 & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Either7Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    const T1 & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Either7Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    const T2 & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Either7Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    const T3 & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    AsCase3() const {
        RHETORIC_ASSERT(tag_ == Either7Tag::Case3);
        return storage_.value3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    const T4 & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    AsCase4() const {
        RHETORIC_ASSERT(tag_ == Either7Tag::Case4);
        return storage_.value4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    const T5 & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    AsCase5() const {
        RHETORIC_ASSERT(tag_ == Either7Tag::Case5);
        return storage_.value5;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    const T6 & 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    AsCase6() const {
        RHETORIC_ASSERT(tag_ == Either7Tag::Case6);
        return storage_.value6;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Storage::Storage() {}

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Storage::~Storage() {}
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Either7Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Either7Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Either7Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    InitValue3(const T3 & value) {
        new (&storage_.value3) T3(value);
        tag_ = Either7Tag::Case3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    InitValue4(const T4 & value) {
        new (&storage_.value4) T4(value);
        tag_ = Either7Tag::Case4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    InitValue5(const T5 & value) {
        new (&storage_.value5) T5(value);
        tag_ = Either7Tag::Case5;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    InitValue6(const T6 & value) {
        new (&storage_.value6) T6(value);
        tag_ = Either7Tag::Case6;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void 
    Either7<T0, T1, T2, T3, T4, T5, T6>::
    Deinit() {
        switch (tag_) {
            case Either7Tag::Case0:
                storage_.value0.~T0();
                break;
            case Either7Tag::Case1:
                storage_.value1.~T1();
                break;
            case Either7Tag::Case2:
                storage_.value2.~T2();
                break;
            case Either7Tag::Case3:
                storage_.value3.~T3();
                break;
            case Either7Tag::Case4:
                storage_.value4.~T4();
                break;
            case Either7Tag::Case5:
                storage_.value5.~T5();
                break;
            case Either7Tag::Case6:
                storage_.value6.~T6();
                break;
        }
    }
    
    template <Either7Tag G, typename T>
    Either7CaseWrapper<G, T>::Either7CaseWrapper(const T & value):
    value(value)
    {}

    template <Either8Tag G, typename T>
    Either8CaseWrapper<G, T>

    EitherCase(const T & value) {
        return Either8CaseWrapper<G, T>(value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case0, T0> & value) {
        InitValue0(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case1, T1> & value) {
        InitValue1(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case2, T2> & value) {
        InitValue2(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case3, T3> & value) {
        InitValue3(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case4, T4> & value) {
        InitValue4(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case5, T5> & value) {
        InitValue5(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case6, T6> & value) {
        InitValue6(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8CaseWrapper<Either8Tag::Case7, T7> & value) {
        InitValue7(value.value);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(const Either8<T0, T1, T2, T3, T4, T5, T6, T7> & other) {
        switch (other.tag()) {
            case Either8Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either8Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either8Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either8Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either8Tag::Case4:
                InitValue4(other.AsCase4());
                break;
            case Either8Tag::Case5:
                InitValue5(other.AsCase5());
                break;
            case Either8Tag::Case6:
                InitValue6(other.AsCase6());
                break;
            case Either8Tag::Case7:
                InitValue7(other.AsCase7());
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Either8(
        const Either8<U0, U1, U2, U3, U4, U5, U6, U7> & other,
        std::enable_if_t<
            std::is_convertible<U0, T0>::value &&
            std::is_convertible<U1, T1>::value &&
            std::is_convertible<U2, T2>::value &&
            std::is_convertible<U3, T3>::value &&
            std::is_convertible<U4, T4>::value &&
            std::is_convertible<U5, T5>::value &&
            std::is_convertible<U6, T6>::value &&
            std::is_convertible<U7, T7>::value
        > *)
    {
        switch (other.tag()) {
            case Either8Tag::Case0:
                InitValue0(static_cast<T0>(other.AsCase0()));
                break;
            case Either8Tag::Case1:
                InitValue1(static_cast<T1>(other.AsCase1()));
                break;
            case Either8Tag::Case2:
                InitValue2(static_cast<T2>(other.AsCase2()));
                break;
            case Either8Tag::Case3:
                InitValue3(static_cast<T3>(other.AsCase3()));
                break;
            case Either8Tag::Case4:
                InitValue4(static_cast<T4>(other.AsCase4()));
                break;
            case Either8Tag::Case5:
                InitValue5(static_cast<T5>(other.AsCase5()));
                break;
            case Either8Tag::Case6:
                InitValue6(static_cast<T6>(other.AsCase6()));
                break;
            case Either8Tag::Case7:
                InitValue7(static_cast<T7>(other.AsCase7()));
                break;
        }
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7> & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    operator= (const Either8<T0, T1, T2, T3, T4, T5, T6, T7> & other) {
        Deinit();
        
        switch (other.tag()) {
            case Either8Tag::Case0:
                InitValue0(other.AsCase0());
                break;
            case Either8Tag::Case1:
                InitValue1(other.AsCase1());
                break;
            case Either8Tag::Case2:
                InitValue2(other.AsCase2());
                break;
            case Either8Tag::Case3:
                InitValue3(other.AsCase3());
                break;
            case Either8Tag::Case4:
                InitValue4(other.AsCase4());
                break;
            case Either8Tag::Case5:
                InitValue5(other.AsCase5());
                break;
            case Either8Tag::Case6:
                InitValue6(other.AsCase6());
                break;
            case Either8Tag::Case7:
                InitValue7(other.AsCase7());
                break;
        }

        return *this;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::~Either8() {
        Deinit();
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8Tag
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    tag() const {
        return tag_;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T0 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase0() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case0);
        return storage_.value0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T1 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase1() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case1);
        return storage_.value1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T2 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase2() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case2);
        return storage_.value2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T3 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase3() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case3);
        return storage_.value3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T4 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase4() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case4);
        return storage_.value4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T5 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase5() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case5);
        return storage_.value5;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T6 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase6() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case6);
        return storage_.value6;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    const T7 & 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    AsCase7() const {
        RHETORIC_ASSERT(tag_ == Either8Tag::Case7);
        return storage_.value7;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Storage::Storage() {}

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Storage::~Storage() {}
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue0(const T0 & value) {
        new (&storage_.value0) T0(value);
        tag_ = Either8Tag::Case0;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue1(const T1 & value) {
        new (&storage_.value1) T1(value);
        tag_ = Either8Tag::Case1;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue2(const T2 & value) {
        new (&storage_.value2) T2(value);
        tag_ = Either8Tag::Case2;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue3(const T3 & value) {
        new (&storage_.value3) T3(value);
        tag_ = Either8Tag::Case3;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue4(const T4 & value) {
        new (&storage_.value4) T4(value);
        tag_ = Either8Tag::Case4;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue5(const T5 & value) {
        new (&storage_.value5) T5(value);
        tag_ = Either8Tag::Case5;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue6(const T6 & value) {
        new (&storage_.value6) T6(value);
        tag_ = Either8Tag::Case6;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    InitValue7(const T7 & value) {
        new (&storage_.value7) T7(value);
        tag_ = Either8Tag::Case7;
    }
    
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void 
    Either8<T0, T1, T2, T3, T4, T5, T6, T7>::
    Deinit() {
        switch (tag_) {
            case Either8Tag::Case0:
                storage_.value0.~T0();
                break;
            case Either8Tag::Case1:
                storage_.value1.~T1();
                break;
            case Either8Tag::Case2:
                storage_.value2.~T2();
                break;
            case Either8Tag::Case3:
                storage_.value3.~T3();
                break;
            case Either8Tag::Case4:
                storage_.value4.~T4();
                break;
            case Either8Tag::Case5:
                storage_.value5.~T5();
                break;
            case Either8Tag::Case6:
                storage_.value6.~T6();
                break;
            case Either8Tag::Case7:
                storage_.value7.~T7();
                break;
        }
    }
    
    template <Either8Tag G, typename T>
    Either8CaseWrapper<G, T>::Either8CaseWrapper(const T & value):
    value(value)
    {}

}
