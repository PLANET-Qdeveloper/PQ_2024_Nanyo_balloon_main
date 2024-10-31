	//
// Created by genta on 2024/05/29.
//

#include "lora.h"

#include <sys/types.h>

extern UART_HandleTypeDef huart1;
uint8_t buffer[512];
int lora_init(){
    reset_comm_power();
	HAL_GPIO_WritePin(RM92A_RESET_GPIO_Port, RM92A_RESET_Pin, GPIO_PIN_SET);
    uint8_t config[] = "\r\r1\ra40\ra40\rc0\rd65534\re0\ri0\rl1\r0\rp1\r0\rp2\r0\rt0\rxs";
    uint8_t down[1];
    printf("\r\n");
    ///HAL_IWDG_Refresh(&hiwdg);
    HAL_Delay(500);
    for (size_t i = 0; i < sizeof(config); i++) {
     		down[0] = config[i];
     		HAL_UART_Transmit(&huart1, down, 1,10);
     		///HAL_IWDG_Refresh(&hiwdg);
     		HAL_Delay(300);
     }
    printf("\r\n");
    printf("\r\n");
    HAL_Delay(200);
	return 0;
}

int lora_send(const uint8_t *text, size_t size){
	uint8_t down[0] = {};
	for(int j = 0; j < size; j++)
	{
		HAL_UART_Transmit(&huart1, &text[j], 1,10);
	}
	return 0;
}
