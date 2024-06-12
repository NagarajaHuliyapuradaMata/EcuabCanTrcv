#ifdef __cplusplus
extern "C"
{
#endif

#include "EcuabCanTrcv.hpp"
#include "McalDio.hpp"

static void WaitHard(uint32 ulMicroSeconds);

void EcuabTrcv_Standby(void){
  McalDio_output_off(GPIO_EN_TJA);
  WaitHard(20);
  McalDio_output_off(GPIO_STB_TJA);
  WaitHard(20);
}

void EcuabTrcv_Normal(void){
  McalDio_output_on(GPIO_STB_TJA);
  McalDio_output_on(GPIO_EN_TJA);
}

boolean EcuabTrcv_GetWakeupFlag(void){
  boolean bRetVal;
  if(McalDio_input_read(GPIO_ERR_TJA) == 0){
    bRetVal = TRUE;
  }
  else{
    bRetVal = FALSE;
  }
  return bRetVal;
}

static void WaitHard(uint32 ulMicroSeconds){
    uint32 ulTicks = ulMicroSeconds * 12;
    while(ulTicks--);
}

#ifdef __cplusplus
}
#endif
