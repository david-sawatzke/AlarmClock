#include "main.h"

static GPIO_InitTypeDef  GPIO_InitStruct;
static DISP_HandleTypeDef DISP_HandleStruct;
int main(void)
{
    HAL_Init();
    HAL_Delay(500); //To let everything else start
    __GPIOA_CLK_ENABLE();
    __GPIOB_CLK_ENABLE();
    DISP_HandleStruct.D4.Port = GPIOA;
    DISP_HandleStruct.D4.Pin = GPIO_PIN_5;
    DISP_HandleStruct.D5.Port = GPIOA;
    DISP_HandleStruct.D5.Pin = GPIO_PIN_6;
    DISP_HandleStruct.D6.Port = GPIOA;
    DISP_HandleStruct.D6.Pin = GPIO_PIN_7;
    DISP_HandleStruct.D7.Port = GPIOB;
    DISP_HandleStruct.D7.Pin = GPIO_PIN_1;
    DISP_HandleStruct.RS.Port = GPIOA;
    DISP_HandleStruct.RS.Pin = GPIO_PIN_9;
    DISP_HandleStruct.E.Port = GPIOA;
    DISP_HandleStruct.E.Pin = GPIO_PIN_10;
    DISP_Init(&DISP_HandleStruct);
    DISP_WriteTimeDate(&DISP_HandleStruct,10,11,12,13,14);
    while(1){
	HAL_Delay(1000);
	DISP_WriteTimeDate(&DISP_HandleStruct,HAL_GetTick() /1000 %60,11,12,13,14);
    }
}
