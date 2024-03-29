//
// Win32\ReleaseAVX\renderer_ispc_sse4.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#ifndef ISPC_WIN32_RELEASEAVX_RENDERER_ISPC_SSE4_H
#define ISPC_WIN32_RELEASEAVX_RENDERER_ISPC_SSE4_H

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
    extern bool Renderer__pick(void * _camera, float x, float y, void * _scene, struct vec3f &p);
    extern int32_t Renderer__renderFrame(void * _this, void * camera, void * scene, void * toneMapper, void * swapchain, const int32_t accuMode);
    extern void Renderer__renderFrameInit(void * _this, void * scene);
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
} /* end extern C */
#endif // __cplusplus


#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus

#endif // ISPC_WIN32_RELEASEAVX_RENDERER_ISPC_SSE4_H
