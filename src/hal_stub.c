/*
 *  Copyright 2018 Frank Hunleth, Mark Sebald
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * I2C NIF implementation.
 */

#include "i2c_nif.h"
#include <string.h>

int hal_i2c_open(const char *device)
{
    return 0;
}

void hal_i2c_close(int fd)
{
}

int hal_i2c_transfer(int fd,
                     unsigned int addr,
                     const uint8_t *to_write, size_t to_write_len,
                     uint8_t *to_read, size_t to_read_len)
{
    if (to_read_len > 0)
        memset(to_read, 0, to_read_len);

    return 0;
}
