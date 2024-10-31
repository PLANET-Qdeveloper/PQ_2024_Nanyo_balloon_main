//
// Created by genta on 2024/05/29.
//

#ifndef BALLOON_MAIN_LORA_H
#define BALLOON_MAIN_LORA_H

#include "main.h"
#include "power/power.h"
#include <stdio.h>
#include <stdarg.h>
int lora_init();
int lora_send(const uint8_t *text, size_t size);

#endif //BALLOON_MAIN_LORA_H
