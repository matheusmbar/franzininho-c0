#ifndef LIB_DEVICE_GPIO_PIN_H_
#define LIB_DEVICE_GPIO_PIN_H_

#include "gpio.h"
#include "stm32c011xx.h"

typedef enum { kGpioLevelHigh, kGpioLevelLow, kGpioLevelUnknown } GpioLevel;

typedef struct {
  GPIO_TypeDef *port;
  uint16_t pin;
} Gpio;

void GpioSetHigh(const Gpio *gpio);
void GpioSetLow(const Gpio *gpio);
GpioLevel GpioGetLevel(const Gpio *gpio);

#endif  // LIB_DEVICE_GPIO_PIN_H_
