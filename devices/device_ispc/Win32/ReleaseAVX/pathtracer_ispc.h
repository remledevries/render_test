//
// Win32\ReleaseAVX\pathtracer_ispc.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#ifndef ISPC_WIN32_RELEASEAVX_PATHTRACER_ISPC_H
#define ISPC_WIN32_RELEASEAVX_PATHTRACER_ISPC_H

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
    extern void *  PathTracer__new(const int32_t &maxDepth, const float &minContribution, const float &epsilon, const int32_t &spp, void * backplate);
#if defined(__cplusplus) && !defined(__ISPC_NO_EXTERN_C)
} /* end extern C */
#endif // __cplusplus



#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus

#endif // ISPC_WIN32_RELEASEAVX_PATHTRACER_ISPC_H
