#pragma once

#define RHETORIC_NON_COPYABLE(type) \
type(const type & other) = delete; \
type & operator=(const type & other) = delete;

#define RHETORIC_EQUATABLE_DEFAULT(type) \
bool operator!=(const type & other) const { return !(*this == other); }

#define RHETORIC_COMPARABLE_DEFAULT(type) \
bool operator>(const type & other) const { return other < *this; }\
bool operator<=(const type & other) const { return (*this < other) || (*this == other); }\
bool operator>=(const type & other) const { return (*this > other) || (*this == other); }
