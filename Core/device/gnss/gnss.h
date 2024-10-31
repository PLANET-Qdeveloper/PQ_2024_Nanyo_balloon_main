//
// Created by 児玉源太郎 on 2024/07/04.
//

#ifndef GNSS_H
#define GNSS_H

#include "gnss/minmea.h"
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "main.h"

typedef struct
{
    struct minmea_sentence_gsa gsa;
    uint32_t gsa_time;
    struct minmea_sentence_gga gga;
    uint32_t gga_time;
    uint32_t recent_timestamp;
    struct tm recent_time;
} gnss_data_t;

int gnss_init();

int feed_nmea(uint8_t code);

#endif //GNSS_H
