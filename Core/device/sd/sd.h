//
// Created by genta on 2024/06/07.
//

#ifndef BALLOON_MAIN_SD_H
#define BALLOON_MAIN_SD_H
#include "fatfs.h"
#include "errno.h"
#include "stdio.h"

#define SD_MAX_TRY_NUM 5
#define SD_DELAY 10

int init_sd();
int write_line(const uint8_t *text, size_t size);


#define FATFS_TRY(f) \
    for(int i = 0; i < SD_MAX_TRY_NUM; i++){ \
    f_res = f; \
    if(f_res  == FR_OK || f_res == FR_EXIST) \
    { \
    break; \
    } \
    if(i == SD_MAX_TRY_NUM){ \
    return f_res; \
    }                \
    }



#endif //BALLOON_MAIN_SD_H


