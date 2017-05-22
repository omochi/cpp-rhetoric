#pragma once

#include "./assert.h"
#include "./std_dependency.h"
#include "./ptr.h"

namespace rhetoric {
    class Data : public std::enable_shared_from_this<Data> {
    public:
        Data();
        Data(int size);
        Data(const void * bytes,
             int size,
             bool copy = true,
             bool free_when_done = true);
        ~Data();

        const void * bytes() const;
        void * bytes();

        int size() const;
        void set_size(int value);

        void Append(const Ptr<const Data> & data);

        void ReserveCapacity(int capacity);
    private:
        void * bytes_;
        int capacity_;
        int size_;
        bool free_when_done_;
    };
}
