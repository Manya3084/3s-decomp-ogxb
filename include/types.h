#pragma once

#if defined(_MSC_VER)
/* VC7.1 compiles C89: no _Static_assert and no __builtin_offsetof. A
 * negative array size makes a failed assert an error (C2118). */
#define XB_SA_CAT_(a, b) a##b
#define XB_SA_CAT(a, b) XB_SA_CAT_(a, b)
#define _Static_assert(e, m) typedef char XB_SA_CAT(xb_static_assert_, __LINE__)[(e) ? 1 : -1]
#define __builtin_offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

/* MSVC-only spellings the Xbox code needs, portable for the gcc check. */
#if defined(_MSC_VER)
#define XB_ALIGN16 __declspec(align(16))
#define XB_STDCALL __stdcall
#define XB_FASTCALL __fastcall
#else
#define XB_ALIGN16 __attribute__((aligned(16)))
#define XB_STDCALL __attribute__((stdcall))
#define XB_FASTCALL __attribute__((fastcall))
#endif

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
