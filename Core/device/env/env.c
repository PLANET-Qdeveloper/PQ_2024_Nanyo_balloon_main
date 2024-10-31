//
// Created by 児玉源太郎 on 2024/07/04.
//

#include "env.h"

env_data_t env_data;

int read_env_data()
{
    bme280_data_readout_template(&env_data);
    return -1;
}