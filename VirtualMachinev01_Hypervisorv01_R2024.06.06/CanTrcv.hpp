#ifndef _CANTRCV_H
#define _CANTRCV_H

#include "Types_EcuabTrcvCan.hpp"

extern void    TRCV_Standby       (void);
extern void    TRCV_Normal        (void);
extern boolean TRCV_GetWakeupFlag (void);

#endif

