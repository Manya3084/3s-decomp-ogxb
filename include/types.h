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

/* A float to an unsigned 32-bit integer as the Xbox's compiler does it: a
 * negative value wraps (-192 becomes 0xFFFFFF40), which retail code
 * relies on when it stores the result in a signed variable. C leaves the
 * conversion undefined, and arm64 clamps a negative value to 0. */
#if defined(_MSC_VER)
#define XB_F2U32(f) ((u32)(f))
#else
#define XB_F2U32(f) ((u32)(s64)(f))
#endif

/* A table read past its end (an index the table has no entry for: a
 * damage state, an effect type): retail read what followed the table in
 * its image. A build of its own lays its globals out otherwise, so past
 * the end the bytes come from retail's image (xb_retail_or, the port's
 * src/port/retail.c), at the table's retail address va. n is the table's
 * entry count. XB_PAST_ROW gives a row of a two-dimensional table. */
#if defined(_MSC_VER)
#define XB_PAST(tbl, n, va, i) ((tbl)[i])
#define XB_PAST_ROW(tbl, n, va, i) ((tbl)[i])
#else
const void* xb_retail_or(const void* live, u32 va, s32 off);
#define XB_PAST(tbl, n, va, i)                                                                                         \
    ((u32)(i) < (u32)(n) ? (tbl)[i]                                                                                    \
                         : *(const __typeof__((tbl)[0])*)xb_retail_or((tbl), (va), (s32)(i) * (s32)sizeof((tbl)[0])))
#define XB_PAST_ROW(tbl, n, va, i)                                                                                     \
    ((u32)(i) < (u32)(n) ? (tbl)[i]                                                                                    \
                         : (const __typeof__((tbl)[0][0])*)xb_retail_or((tbl), (va), (s32)(i) * (s32)sizeof((tbl)[0])))
#endif

/* A C++ method call from C. A method is written XB_FASTCALL with an
 * unused edx parameter, so a direct call would load edx. __fastcall
 * passes a struct on the stack, so calling the method through a
 * prototype whose stack arguments are XB_ARG leaves edx alone, which is
 * what a thiscall does:
 *   XB_ARG a; a.v = i;
 *   ((void (XB_FASTCALL *)(u8 *, XB_ARG))method)(self, a);
 */
typedef struct {
    s32 v;
} XB_ARG;

/* 32-bit target: pointers, sizes, and pointer-sized integers are 4 bytes. */
typedef s32 intptr_t;
typedef u32 uintptr_t;
typedef u32 size_t;
typedef s32 ssize_t;
