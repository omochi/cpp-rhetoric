#pragma once

#define RHETORIC_COMPARABLE_DEFAULT(type) \
bool operator>(const type & other) const { return other < *this; }\
bool operator<=(const type & other) const { return (*this == other) || (*this < other); }\
bool operator>=(const type & other) const { return (*this == other) || (*this > other); }
