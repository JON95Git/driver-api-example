#include "stdio.h"
#include "driver.h"

static struct driver_api my_driver_api_funcs = {
      .init = NULL
};

const struct context ctx = {.name = "x86 driver", .api = &my_driver_api_funcs};
