#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupport_c.h"
#include "stm32c011xx.h"

extern "C" {
#include "device/gpio_pin.h"
}

TEST_GROUP(GPIO) {
  GPIO_TypeDef port_1;
  uint16_t pin = 1;
  Gpio gpio_1 = {&port_1, pin};
  Gpio gpio_invalid = {NULL, pin};
  GpioLevel level = kGpioLevelLow;

  void teardown() {
    mock_c()->checkExpectations();
    mock_c()->clear();
  }
};

TEST(GPIO, SetHigh) {
  mock_c()
      ->expectOneCall("HAL_GPIO_WritePin")
      ->withConstPointerParameters("GPIO_TypeDef", gpio_1.port)
      ->withUnsignedIntParameters("GPIO_Pin", gpio_1.pin)
      ->withUnsignedIntParameters("PinState", GPIO_PIN_SET);

  GpioSetHigh(&gpio_1);
}

TEST(GPIO, SetHighInvalidArg) {
  mock_c()->expectNoCall("HAL_GPIO_WritePin");

  GpioSetHigh(NULL);
  GpioSetHigh(&gpio_invalid);
}

TEST(GPIO, SetLow) {
  mock_c()
      ->expectOneCall("HAL_GPIO_WritePin")
      ->withConstPointerParameters("GPIO_TypeDef", gpio_1.port)
      ->withUnsignedIntParameters("GPIO_Pin", gpio_1.pin)
      ->withUnsignedIntParameters("PinState", GPIO_PIN_RESET);

  GpioSetLow(&gpio_1);
}

TEST(GPIO, SetLowInvalidArg) {
  mock_c()->expectNoCall("HAL_GPIO_WritePin");

  GpioSetLow(NULL);
  GpioSetLow(&gpio_invalid);
}

TEST(GPIO, Toggle) {
  mock_c()
      ->expectOneCall("HAL_GPIO_TogglePin")
      ->withConstPointerParameters("GPIO_TypeDef", gpio_1.port)
      ->withUnsignedIntParameters("GPIO_Pin", gpio_1.pin);

  GpioToggle(&gpio_1);
}

TEST(GPIO, ToggleInvalidArg) {
  mock_c()->expectNoCall("HAL_GPIO_TogglePin");

  GpioToggle(NULL);
  GpioToggle(&gpio_invalid);
}

TEST(GPIO, GetLevel) {
  mock_c()
      ->expectOneCall("HAL_GPIO_ReadPin")
      ->withConstPointerParameters("GPIO_TypeDef", gpio_1.port)
      ->withUnsignedIntParameters("GPIO_Pin", gpio_1.pin)
      ->andReturnUnsignedIntValue(GPIO_PIN_RESET);
  level = GpioGetLevel(&gpio_1);
  CHECK_EQUAL(kGpioLevelLow, level);

  mock_c()
      ->expectOneCall("HAL_GPIO_ReadPin")
      ->withConstPointerParameters("GPIO_TypeDef", gpio_1.port)
      ->withUnsignedIntParameters("GPIO_Pin", gpio_1.pin)
      ->andReturnUnsignedIntValue(GPIO_PIN_SET);
  level = GpioGetLevel(&gpio_1);
  CHECK_EQUAL(kGpioLevelHigh, level);
}

TEST(GPIO, GetLevelInvalidArg) {
  mock_c()->expectNoCall("HAL_GPIO_ReadPin");
  level = GpioGetLevel(NULL);
  CHECK_EQUAL(kGpioLevelUnknown, level);

  GpioGetLevel(&gpio_invalid);
  CHECK_EQUAL(kGpioLevelUnknown, level);
}
