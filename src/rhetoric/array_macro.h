#pragma once

#define RHETORIC_ARRAY_SIZE(a)   \
(   sizeof(a) / sizeof( *(a) )  )
