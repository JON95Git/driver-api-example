#include <stdio.h>
#include "include/driver.h"

const struct context ctx;

int main()
{
    int ret = 0;
    char buff[2];

    ret = driver_api_init(&ctx, 10, 20);
    if (ret) {
        printf("Error: %d\n", ret);
    }

    driver_api_get(&ctx, buff);

    return 0;
}
