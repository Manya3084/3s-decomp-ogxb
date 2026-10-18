/* stdint.h for the XDK 5849 compiler (VC7.1 ships none). types.h already
 * defines intptr_t and uintptr_t. */
#pragma once

#include "types.h"

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef __int64 int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;
