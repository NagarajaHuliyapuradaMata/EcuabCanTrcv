#ifdef __cplusplus
extern "C"
{
#endif

#include "EcuabCanTrcv.hpp"
#include "McalDio.hpp"

static void WaitHard(uint32 ulMicroSeconds);

void EcuabTrcv_Standby(void){
  GPIO_output_off(GPIO_EN_TJA);
  WaitHard(20);
  GPIO_output_off(GPIO_STB_TJA);
  WaitHard(20);
}

void EcuabTrcv_Normal(void){
  GPIO_output_on(GPIO_STB_TJA);
  GPIO_output_on(GPIO_EN_TJA);
}

boolean EcuabTrcv_GetWakeupFlag(void){
  boolean bRetVal;
  if(GPIO_input_read(GPIO_ERR_TJA) == 0){
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
