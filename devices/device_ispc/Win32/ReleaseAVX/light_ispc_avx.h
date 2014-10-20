//
// Win32\ReleaseAVX\light_ispc_avx.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#ifndef ISPC_WIN32_RELEASEAVX_LIGHT_ISPC_AVX_H
#define ISPC_WIN32_RELEASEAVX_LIGHT_ISPC_AVX_H

#include <stdint.h>



#ifdef __cplusplus
namespace ispc { /* namespace */
#endif // __cplusplus
///////////////////////////////////////////////////////////////////////////
// Enumerator types with external visibility from ispc code
///////////////////////////////////////////////////////////////////////////

#ifndef __ISPC_ENUM_LightType__
#define __ISPC_ENUM_LightType__
enum LightType {
    NORMAL_LIGHT = 0,
    AREA_LIGHT = 1,
    ENV_LIGHT = 4,
    PRECOMPUTED_LIGHT = 8 
};
#endif

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
    extern enum LightType Light__getType(void * _this);
    extern void *  Light__shape(void * _this);
    extern void *  Light__transform(void * _this, const struct vec3f &vx, const struct vec3f &vy, const struct vec3f &vz, const struct vec3f &p);
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
} /* end extern C */
#endif // __cplusplus


#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus

#endif // ISPC_WIN32_RELEASEAVX_LIGHT_ISPC_AVX_H