#ifndef DRIVER_H
#define DRIVER_H

#include <stdio.h>

struct context {
      const char *name;
      const void *api;
};

typedef int (*driver_api_init_t)(const struct context *ctx, int foo, int bar);
typedef void (*driver_api_get_t)(const struct context *ctx, void *baz);

struct driver_api {
      driver_api_init_t init;
      driver_api_get_t get;
};

static inline int driver_api_init(const struct context *ctx, int foo, int bar)
{
      struct driver_api *api;

      api = (struct driver_api *)ctx->api;
      if (api->init == NULL) {
            printf("Not implemented\n");
            return 0;
      }
      return api->init(ctx, foo, bar);
}

static inline void driver_api_get(const struct context *ctx, void *baz)
{
      struct driver_api *api;

      api = (struct driver_api *)ctx->api;
      if (api->get == NULL) {
            printf("Not implemented\n");
            return;
      }
      api->get(ctx, baz);
}

#endif /* DRIVER_H */
