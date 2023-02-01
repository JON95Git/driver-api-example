#ifndef DRIVER_H
#define DRIVER_H

#include <stdio.h>

/* Generic context */
struct context {
      const char *name;
      const void *api;
};

/* Function pointers */
typedef int (*driver_api_init_t)(const struct context *ctx, int foo, int bar);
typedef void (*driver_api_get_t)(const struct context *ctx, void *baz);
typedef void (*driver_api_set_t)(const struct context *ctx, int var);

/* Generic API */
struct driver_api {
      driver_api_init_t init;
      driver_api_get_t get;
      driver_api_set_t set;
};

/* Global context */
extern const struct context ctx;

/* Generic functions */

static inline int driver_api_init(const struct context *ctx, int foo, int bar)
{
      struct driver_api *api;

      api = (struct driver_api *)ctx->api;

      /* Test if function is implemented */
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

      /* Test if function is implemented */
      if (api->get == NULL) {
            printf("Not implemented\n");
            return;
      }
      api->get(ctx, baz);
}

static inline void driver_api_set(const struct context *ctx, int var)
{
      struct driver_api *api;

      api = (struct driver_api *)ctx->api;

      /* Test if function is implemented */
      if (api->set == NULL) {
            printf("Not implemented\n");
            return;
      }
      api->set(ctx, var);
}

#endif /* DRIVER_H */
