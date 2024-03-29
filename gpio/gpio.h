/*
 * gpio.h
 *
 *  Created on: 24 wrz 2017
 *      Author: filip
 */

#ifndef GPIO_H_
#define GPIO_H_


typedef enum {
	/* Push-Pull */
	gpio_mode_output_PP_2MHz = 2,
	gpio_mode_output_PP_10MHz = 1,
	gpio_mode_output_PP_50MHz = 3,

	/* Open-Drain */
	gpio_mode_output_OD_2MHz = 6,
	gpio_mode_output_OD_10MHz = 5,
	gpio_mode_output_OD_50MHz = 7,

	/* Push-Pull */
	gpio_mode_alternate_PP_2MHz = 10,
	gpio_mode_alternate_PP_10MHz = 9,
	gpio_mode_alternate_PP_50MHz = 11,

	/* Open-Drain */
	gpio_mode_alternate_OD_2MHz = 14,
	gpio_mode_alternate_OD_10MHz = 13,
	gpio_mode_alternate_OD_50MHz = 15,

	/* Analog input (ADC) */
	gpio_mode_input_analog = 0,

	/* Floating digital input. */
	gpio_mode_input_floating = 4,

	/* Digital input with pull-up/down (depending on the ODR reg.). */
	gpio_mode_input_pull = 8
} GpioMode_t;

typedef enum {
	PA0 = 0x00000001,
	PA1 = 0x00000002,
	PA2 = 0x00000004,
	PA3 = 0x00000008,
	PA4 = 0x00000010,
	PA5 = 0x00000020,
	PA6 = 0x00000040,
	PA7 = 0x00000080,
	PA8 = 0x00000100,
	PA9 = 0x00000200,
	PA10 = 0x00000400,
	PA11 = 0x00000800,
	PA12 = 0x00001000,
	PA13 = 0x00002000,
	PA14 = 0x00004000,
	PA15 = 0x00008000,

	PB0 = 0x00000001,
	PB1 = 0x00000002,
	PB2 = 0x00000004,
	PB3 = 0x00000008,
	PB4 = 0x00000010,
	PB5 = 0x00000020,
	PB6 = 0x00000040,
	PB7 = 0x00000080,
	PB8 = 0x00000100,
	PB9 = 0x00000200,
	PB10 = 0x00000400,
	PB11 = 0x00000800,
	PB12 = 0x00001000,
	PB13 = 0x00002000,
	PB14 = 0x00004000,
	PB15 = 0x00008000,

	PC0 = 0x00000001,
	PC1 = 0x00000002,
	PC2 = 0x00000004,
	PC3 = 0x00000008,
	PC4 = 0x00000010,
	PC5 = 0x00000020,
	PC6 = 0x00000040,
	PC7 = 0x00000080,
	PC8 = 0x00000100,
	PC9 = 0x00000200,
	PC10 = 0x00000400,
	PC11 = 0x00000800,
	PC12 = 0x00001000,
	PC13 = 0x00002000,
	PC14 = 0x00004000,
	PC15 = 0x00008000,

} GpioPin_t;


void gpio_pin_cfg(GPIO_TypeDef * const port, GpioPin_t pin, GpioMode_t mode);

#endif /* GPIO_H_ */
