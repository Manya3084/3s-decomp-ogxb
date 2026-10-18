#pragma once

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

#if defined(_MSC_VER)
typedef __int64 s64;
typedef unsigned __int64 u64;
#else
typedef signed long long s64;
typedef unsigned long long u64;
#endif

/* 32-bit target: pointers, sizes, and pointer-sized integers are 4 bytes. */
typedef s32 intptr_t;
typedef u32 uintptr_t;
typedef u32 size_t;
typedef s32 ssize_t;
