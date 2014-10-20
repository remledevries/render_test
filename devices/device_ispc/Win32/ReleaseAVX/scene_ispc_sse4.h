//
// Win32\ReleaseAVX\scene_ispc_sse4.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#ifndef ISPC_WIN32_RELEASEAVX_SCENE_ISPC_SSE4_H
#define ISPC_WIN32_RELEASEAVX_SCENE_ISPC_SSE4_H

#include <stdint.h>



#ifdef __cplusplus
namespace ispc { /* namespace */
#endif // __cplusplus

///////////////////////////////////////////////////////////////////////////
// Functions exported from ispc code
///////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
extern "C" {
#endif // __cplusplus
    extern void *  Scene__new(void * accel, void * traverserTy, const int32_t num_allLights, void *  * allLights, const int32_t num_envLights, void *  * envLights, const int32_t num_geometries, void *  * geometry);
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
} /* end extern C */
#endif // __cplusplus


#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus

#endif // ISPC_WIN32_RELEASEAVX_SCENE_ISPC_SSE4_H
