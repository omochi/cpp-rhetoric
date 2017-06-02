#pragma once

#define RHETORIC_EQUATABLE_DEFAULT(type) \
bool operator!=(const type & other) const { return !(*this == other); }
