#include "./data.h"

namespace rhetoric {
    Data::Data():Data(nullptr, 0, true, true)
    {}

    Data::Data(int size):Data(nullptr, size, true, true)
    {}

    Data::Data(const void * bytes,
               int size,
               bool copy,
               bool free_when_done)
    {
        RHETORIC_ASSERT(size >= 0);

        if (copy) {
            RHETORIC_ASSERT(free_when_done);
            free_when_done_ = true;

            if (size > 0) {
                bytes_ = malloc(size);
                RHETORIC_ASSERT(bytes_ != nullptr);
                if (bytes) {
                    memcpy(bytes_, bytes, size);
                }
            } else {
                bytes_ = nullptr;
            }
        } else {
            if (size > 0) {
                RHETORIC_ASSERT(bytes != nullptr);
            }

            bytes_ = const_cast<void *>(bytes);
            free_when_done_ = free_when_done;
        }

        capacity_ = size;
        size_ = size;
    }

    Data::~Data() {
        if (free_when_done_ && bytes_) {
            free(bytes_);
            bytes_ = nullptr;
            capacity_ = 0;
            size_ = 0;
        }
    }

    const void * Data::bytes() const {
        return bytes_;
    }

    void * Data::bytes() {
        return bytes_;
    }

    int Data::size() const {
        return size_;
    }

    void Data::set_size(int value) {
        if (value > capacity_) {
            ReserveCapacity(value);
        }

        size_ = value;
    }

    void Data::Append(const Ptr<const Data> & data) {
        if (data->size_ == 0) {
            return;
        }

        int new_size = size_ + data->size_;
        if (new_size > capacity_) {
            if (new_size <= capacity_ * 2) {
                ReserveCapacity(capacity_ * 2);
            } else {
                ReserveCapacity(new_size);
            }
        }

        memcpy((uint8_t *)bytes_ + size_, data->bytes_, data->size_);
        size_ = new_size;
    }

    void Data::ReserveCapacity(int capacity) {
        RHETORIC_ASSERT(capacity > 0);

        void * new_bytes;
        int new_size = std::min(size_, capacity);

        if (free_when_done_) {
            new_bytes = realloc(bytes_, capacity);
            RHETORIC_ASSERT(new_bytes != nullptr);
        } else {
            new_bytes = malloc(capacity);
            RHETORIC_ASSERT(new_bytes != nullptr);

            if (new_size > 0) {
                memcpy(new_bytes, bytes_, new_size);
            }
        }

        bytes_ = new_bytes;
        capacity_ = capacity;
        size_ = new_size;
        free_when_done_ = true;
    }

    std::string Data::ToString() const {
        return std::string(static_cast<const char *>(bytes_), size_);
    }
}
