#include <stdio.h>
#include "include/driver.h"

int main()
{
    int ret = 0;
    char buff[2];

    ret = driver_api_init(&ctx, 10, 20);
    if (ret) {
        printf("Error: %d\n", ret);
    }

    driver_api_get(&ctx, buff);
    driver_api_set(&ctx, 10);

    return 0;
}
