//
// Win32\ReleaseAVX\metallicpaint_ispc_sse4.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#ifndef ISPC_WIN32_RELEASEAVX_METALLICPAINT_ISPC_SSE4_H
#define ISPC_WIN32_RELEASEAVX_METALLICPAINT_ISPC_SSE4_H

#include <stdint.h>



#ifdef __cplusplus
namespace ispc { /* namespace */
#endif // __cplusplus
#ifndef __ISPC_STRUCT_vec3f__
#define __ISPC_STRUCT_vec3f__
struct vec3f {
    float x;
    float y;
    float z;
};
#endif


///////////////////////////////////////////////////////////////////////////
// Functions exported from ispc code
///////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
extern "C" {
#endif // __cplusplus
    extern void *  MetallicPaint__new(const struct vec3f &shadeColor, const struct vec3f &glitterColor, const float glitterSpread, const float eta);
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
} /* end extern C */
#endif // __cplusplus


#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus

#endif // ISPC_WIN32_RELEASEAVX_METALLICPAINT_ISPC_SSE4_H