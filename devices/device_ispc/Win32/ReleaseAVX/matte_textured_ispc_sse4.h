//
// Win32\ReleaseAVX\matte_textured_ispc_sse4.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#ifndef ISPC_WIN32_RELEASEAVX_MATTE_TEXTURED_ISPC_SSE4_H
#define ISPC_WIN32_RELEASEAVX_MATTE_TEXTURED_ISPC_SSE4_H

#include <stdint.h>



#ifdef __cplusplus
namespace ispc { /* namespace */
#endif // __cplusplus
#ifndef __ISPC_STRUCT_vec2f__
#define __ISPC_STRUCT_vec2f__
struct vec2f {
    float x;
    float y;
};
#endif


///////////////////////////////////////////////////////////////////////////
// Functions exported from ispc code
///////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
extern "C" {
#endif // __cplusplus
    extern void *  MatteTextured__new(void * Kd, const struct vec2f &s0, const struct vec2f &ds);
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
} /* end extern C */
#endif // __cplusplus


#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus

#endif // ISPC_WIN32_RELEASEAVX_MATTE_TEXTURED_ISPC_SSE4_H