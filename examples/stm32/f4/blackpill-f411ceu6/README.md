# WeAct Studio Black Pill (STM32F411CEU6)

This directory contains libopencm3 examples for the WeAct Studio "Black
Pill" development board, built around the STM32F411CEU6 (Cortex-M4,
512K flash, 128K RAM).

## Board details

- MCU: STM32F411CEU6
- External crystal (HSE): 25 MHz
- Onboard LED: PC13 (active-low — pin LOW turns the LED on)
- Onboard user button: PA0
- USB: DFU-capable ROM bootloader (BOOT0 pin), also usable for
  flashing without an external programmer

## Flashing

Via ST-Link/OpenOCD:

```
cd blink
make
make flash
```

Via DFU (no ST-Link required — hold BOOT0, tap RESET, release BOOT0):

```
dfu-util -a 0 -s 0x08000000:leave -D blink.bin
```

## Examples

- `blink/` — toggles the onboard PC13 LED using `gpio_toggle()`.
