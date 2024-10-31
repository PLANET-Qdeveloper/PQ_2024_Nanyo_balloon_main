//
// Created by genta on 2024/05/19.
//

#include "power.h"


void set_comm_power(int mode){
	HAL_GPIO_WritePin(CTRL_COMM_GPIO_Port, CTRL_COMM_Pin, mode);
}
void set_sense_power(int mode){
	HAL_GPIO_WritePin(CTRL_SENSE_GPIO_Port, CTRL_SENSE_Pin, mode);
}
void reset_sense_power(){
	HAL_GPIO_WritePin(CTRL_SENSE_GPIO_Port, CTRL_SENSE_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(CTRL_SENSE_GPIO_Port, CTRL_SENSE_Pin, GPIO_PIN_SET);
}
void reset_comm_power(){
	HAL_GPIO_WritePin(CTRL_COMM_GPIO_Port, CTRL_COMM_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(CTRL_COMM_GPIO_Port, CTRL_COMM_Pin, GPIO_PIN_SET);
}
