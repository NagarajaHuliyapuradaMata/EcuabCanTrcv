#ifndef _CANTRCV_H
#define _CANTRCV_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "Types_McalCan.hpp"
#include "McalDio.hpp"

extern void EcuabTrcv_Standby(void);
extern void EcuabTrcv_Normal(void);
extern boolean EcuabTrcv_GetWakeupFlag(void);

#ifdef __cplusplus
}
#endif
#endif

