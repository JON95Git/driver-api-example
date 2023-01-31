#include "stdio.h"
#include "driver.h"

static int my_driver_init(const struct context *ctx, int foo, int bar)
{
    printf("%s, foo: %d and bar: %d\n",__func__, foo, bar);
    printf("%s \n",ctx->name);
    return 0;
}

static void my_driver_get(const struct context *ctx, void *baz)
{
    printf("%s \n",__func__);
    printf("%s \n",ctx->name);
}

static struct driver_api my_driver_api_funcs = {
      .init = my_driver_init,
      .get = my_driver_get
};

extern const struct context ctx = {.name = "arm driver", .api = &my_driver_api_funcs};

