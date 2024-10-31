//
// Created by genta on 2024/05/19.
//

#ifndef BALLOON_MAIN_POWER_H
#define BALLOON_MAIN_POWER_H

#include <stdint.h>
#include "main.h"

void set_comm_power(int mode);
void set_sense_power(int mode);

void reset_sense_power();
void reset_comm_power();


#endif //BALLOON_MAIN_POWER_H
