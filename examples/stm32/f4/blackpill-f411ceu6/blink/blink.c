/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (c) 2015 Chuck McManis <cmcmanis@mcmanis.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Blink example for the WeAct Studio "Black Pill" board (STM32F411CEU6).
 *
 * The onboard LED is connected to PC13 and is active-low: writing the
 * pin LOW turns the LED ON, writing it HIGH turns the LED OFF.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void gpio_setup(void)
{
	/* Enable GPIOC clock (onboard LED is on PC13). */
	rcc_periph_clock_enable(RCC_GPIOC);

	/* Set GPIO13 (in GPIO port C) to 'output push-pull'. */
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
}

int main(void)
{
	int i;

	gpio_setup();

	while (1) {
		/* LED is active-low: toggle it on/off. */
		gpio_toggle(GPIOC, GPIO13);
		for (i = 0; i < 2000000; i++) {	/* Wait a bit. */
			__asm__("nop");
		}
	}

	return 0;
}
