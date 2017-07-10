#pragma once

#define RHETORIC_NON_COPYABLE(type) \
type(const type & other) = delete; \
type & operator=(const type & other) = delete;
