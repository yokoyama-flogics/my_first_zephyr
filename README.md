# How to build the code

Launch a bash terminal.

```
source ~/zephyrproject/zephyr/zephyr-env.sh
cd my_first_zephyr
mkdir build
cd build
cmake -DBOARD=hifive1 ..
make
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
