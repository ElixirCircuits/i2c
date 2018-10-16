#ifndef I2C_NIF_H
#define I2C_NIF_H


#include "linux/i2c-dev.h"
#include "erl_nif.h"

#include <err.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define DEBUG

#ifdef DEBUG
#define log_location stderr
//#define LOG_PATH "/tmp/elixir_circuits_gpio.log"
#define debug(...) do { enif_fprintf(log_location, __VA_ARGS__); enif_fprintf(log_location, "\r\n"); fflush(log_location); } while(0)
#define error(...) do { debug(__VA_ARGS__); } while (0)
#define start_timing() ErlNifTime __start = enif_monotonic_time(ERL_NIF_USEC)
#define elapsed_microseconds() (enif_monotonic_time(ERL_NIF_USEC) - __start)
#else
#define debug(...)
#define error(...) do { enif_fprintf(stderr, __VA_ARGS__); enif_fprintf(stderr, "\n"); } while(0)
#define start_timing()
#define elapsed_microseconds() 0
#endif

#define I2C_BUFFER_MAX 8192

// I2C NIF Resource.  Maps device name to file descriptor
typedef struct{
    char device[16];
    int fd;
    unsigned addr;
} I2cNifRes;


// Linked list of references to I2C NIF Resources
typedef struct {
    I2cNifRes *res;
    void *next;
} I2cNifResList;


// I2C NIF Private data
typedef struct {
    ErlNifResourceType *i2c_nif_res_type;
    I2cNifResList *i2c_nif_res_list;
    ERL_NIF_TERM atom_ok;
    ERL_NIF_TERM atom_error;
} I2cNifPriv;


// i2c_nif_res_list.c

void del_i2c_nif_res(I2cNifResList **head, I2cNifRes *del_res);
void add_i2c_nif_res(I2cNifResList **head, I2cNifRes *add_res);
int is_i2c_nif_res(I2cNifResList *head, I2cNifRes *chk_res);
int get_i2c_res_fd(I2cNifResList *head, const char *device);

#endif // I2C_NIF_H