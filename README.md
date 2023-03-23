# A simple example of how to develop a portable driver api

A simple example of how to develop a portable driver api - based on [Zephyr device driver](https://docs.zephyrproject.org/latest/kernel/drivers/index.html) model.

## How to build

You can build to three different architectures:

```bash
$ make arm
```

```bash
$ make ppc
```

```bash
$ make x86
```

To clean
```bash
$ make clean
```

## Running
```bash
$ ./driver_api_exe
```
The output depends on the builded target:
- ARM:
    ```bash
    $ ./driver_api_exe
    my_driver_init, foo: 10 and bar: 20
    arm driver 
    my_driver_get 
    arm driver
    ```

- PPC:
    ```bash
    $ ./driver_api_exe
    my_driver_init, foo: 10 and bar: 20
    ppc driver 
    my_driver_get 
    ppc driver
    ```

- X86:
    ```bash
    $ ./driver_api_exe
    Not implemented
    Not implemented
    ```
The API initialization requires an up to date toolchain (C99 or newer).
Using older toolchain requires change the the API initialization.
