#pragma once

#define RHETORIC_C_ARRAY_SIZE(a)   \
(   sizeof(a) / sizeof( *(a) )  )
