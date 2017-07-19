#pragma once

#include "./std_dependency.h"

#include "./accessor_macro.h"
#include "./assert.h"
#include "./concept_macro.h"
#include "./ptr.h"

namespace rhetoric {
    class Data : public std::enable_shared_from_this<Data> {
    public:
        Data();
        Data(size_t size);
        Data(const void * bytes,
             size_t size,
             bool copy = true,
             bool free_when_done = true);
        ~Data();
        
        RHETORIC_NON_COPYABLE(Data)

        const void * bytes() const;
        void * bytes();
        
        RHETORIC_GETTER(size_t, size)
        void set_size(size_t value);
        
        void Append(const Ptr<const Data> & data);

        void ReserveCapacity(size_t capacity);

        std::string ToString() const;
    private:
        void * bytes_;
        size_t capacity_;
        size_t size_;
        bool free_when_done_;
    };
}
