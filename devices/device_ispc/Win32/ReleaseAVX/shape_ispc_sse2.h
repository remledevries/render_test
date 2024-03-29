//
// Win32\ReleaseAVX\shape_ispc_sse2.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#ifndef ISPC_WIN32_RELEASEAVX_SHAPE_ISPC_SSE2_H
#define ISPC_WIN32_RELEASEAVX_SHAPE_ISPC_SSE2_H

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
    extern int32_t Shape__add(void * scene, void * _shape, struct vec3f &lower_o, struct vec3f &upper_o);
    extern int32_t Shape__getNumTriangles(void * _this);
    extern int32_t Shape__getNumVertices(void * _this);
    extern void *  Shape__transform(void * _this, const struct vec3f &vx, const struct vec3f &vy, const struct vec3f &vz, const struct vec3f &p);
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
} /* end extern C */
#endif // __cplusplus


#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus

#endif // ISPC_WIN32_RELEASEAVX_SHAPE_ISPC_SSE2_H
