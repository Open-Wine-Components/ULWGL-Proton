#include "vrclient_private.h"
#include "vrclient_defs.h"
#include "openvr_v1.26.7/ivrclientcore.h"
using namespace vr;
extern "C" {
#include "struct_converters.h"
}
#include "cppIVRChaperone_IVRChaperone_004.h"
#ifdef __cplusplus
extern "C" {
#endif
vr::ChaperoneCalibrationState cppIVRChaperone_IVRChaperone_004_GetCalibrationState(void *linux_side)
{
    vr::ChaperoneCalibrationState _ret;
    _ret = ((IVRChaperone*)linux_side)->GetCalibrationState();
    return _ret;
}

bool cppIVRChaperone_IVRChaperone_004_GetPlayAreaSize(void *linux_side, float *pSizeX, float *pSizeZ)
{
    bool _ret;
    _ret = ((IVRChaperone*)linux_side)->GetPlayAreaSize((float *)pSizeX, (float *)pSizeZ);
    return _ret;
}

bool cppIVRChaperone_IVRChaperone_004_GetPlayAreaRect(void *linux_side, HmdQuad_t *rect)
{
    bool _ret;
    _ret = ((IVRChaperone*)linux_side)->GetPlayAreaRect((vr::HmdQuad_t *)rect);
    return _ret;
}

void cppIVRChaperone_IVRChaperone_004_ReloadInfo(void *linux_side)
{
    ((IVRChaperone*)linux_side)->ReloadInfo();
}

void cppIVRChaperone_IVRChaperone_004_SetSceneColor(void *linux_side, HmdColor_t color)
{
    ((IVRChaperone*)linux_side)->SetSceneColor((vr::HmdColor_t)color);
}

void cppIVRChaperone_IVRChaperone_004_GetBoundsColor(void *linux_side, HmdColor_t *pOutputColorArray, int nNumOutputColors, float flCollisionBoundsFadeDistance, HmdColor_t *pOutputCameraColor)
{
    ((IVRChaperone*)linux_side)->GetBoundsColor((vr::HmdColor_t *)pOutputColorArray, (int)nNumOutputColors, (float)flCollisionBoundsFadeDistance, (vr::HmdColor_t *)pOutputCameraColor);
}

bool cppIVRChaperone_IVRChaperone_004_AreBoundsVisible(void *linux_side)
{
    bool _ret;
    _ret = ((IVRChaperone*)linux_side)->AreBoundsVisible();
    return _ret;
}

void cppIVRChaperone_IVRChaperone_004_ForceBoundsVisible(void *linux_side, bool bForce)
{
    ((IVRChaperone*)linux_side)->ForceBoundsVisible((bool)bForce);
}

void cppIVRChaperone_IVRChaperone_004_ResetZeroPose(void *linux_side, ETrackingUniverseOrigin eTrackingUniverseOrigin)
{
    ((IVRChaperone*)linux_side)->ResetZeroPose((vr::ETrackingUniverseOrigin)eTrackingUniverseOrigin);
}

#ifdef __cplusplus
}
#endif
