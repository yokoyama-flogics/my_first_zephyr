# What is this code?

This is my first app written for RISC-V on HiFive1 and Zephyr OS.
Using PWM functionality to control on-board LED brightness.

# How to build the code

First, launch a bash terminal.
Hereafter, we assume the following environment variables are defined as
mentioned at SiFive freedom-e-sdk GitHub site.

As mentioned below, some versions of OpenOCD is okay but others may fail.
I used SiFive ``riscv-openocd-2018.7.0-x86_64-linux-ubuntu14``.

- ``RISCV_OPENOCD_PATH``
- ``RISCV_PATH``

## Method explained at the site "RISC-V - Getting Started Guide"

Reference: [RISC-V - Getting Started Guide](https://risc-v-getting-started-guide.readthedocs.io/en/latest/index.html)

```
source ~/zephyrproject/zephyr/zephyr-env.sh
cd my_first_zephyr
mkdir build
cd build
cmake -DBOARD=hifive1 ..
make
```

## Much easier way to build

```
source ~/zephyrproject/zephyr/zephyr-env.sh
cd my_first_zephyr
west build -b hifive1 -- -DOPENOCD=$RISCV_OPENOCD_PATH/bin/openocd
```

You can omit any arguments for "west build" by placing the following lines at **the beginning** of the CMakeLists.txt.

```
set(BOARD hifive1)
set(OPENOCD $ENV{RISCV_OPENOCD_PATH}/bin/openocd)
```

# How to write to HiFive 1 Flash ROM

Connect your HiFive 1 to PC USB connector.

```
~/freedom-e-sdk/scripts/upload \
  --elf zephyr/zephyr.elf \
  --openocd $RISCV_OPENOCD_PATH/bin/openocd \
  --gdb $RISCV_PATH/bin/riscv64-unknown-elf-gdb \
  --openocd-config ~/freedom-e-sdk/bsp/sifive-hifive1/openocd.cfg
```

## Much easier way to flash

If you took the "west build" way.

```
west flash
```

If it failed, replacing
~/zephyrproject/zephyr/boards/riscv/hifive1/support/openocd.cfg by
~/freedom-e-sdk/bsp/sifive-hifive1/openocd.cfg may help.

# Dependencies

- [SiFive freedom-e-sdk](https://github.com/sifive/freedom-e-sdk/blob/v201908-branch/README.md)
- [Zephyr Project (zephyr-sdk-0.10.3)](https://docs.zephyrproject.org/latest/getting_started/index.html)
- [Zephyr Project 2.1.99](https://docs.zephyrproject.org/latest/)
- [SiFive OpenOCD 2018.7.0](https://static.dev.sifive.com/dev-tools/riscv-openocd-2018.7.0-x86_64-linux-ubuntu14.tar.gz)

# My Blog

- [Building SiFive HiFive 1 app by Zephyr OS environment (Japanese)](https://flogics.com/wp/ja/2019/12/building-hifive1-app-by-zephyr/)
