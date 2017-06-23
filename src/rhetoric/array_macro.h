#pragma once

#define RHETORIC_ARRAY_SIZE(a)   \
static_cast<int>(                \
    sizeof(a) / sizeof( *(a) )   \
)
