#include <iostream>

#include "CppUTest/TestHarness.h"

extern "C" {
#include "device/led.h"
}

TEST_GROUP(Led) {
  GPIO_TypeDef port_1;
  uint16_t pin = 1;
  Gpio gpio_1 = {&port_1, pin};
};

TEST(Led, SetOn) {
  LedSetOn(&gpio_1);
}
