// GPIO.h
#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx_hal.h"   // Include STM32 HAL header for GPIO functionality
#include <stdint.h>          // Include standard integer types

class GPIO {
public:
    // Enum for pin direction
    enum class Direction {
        INPUT,
        OUTPUT
    };

    // Enum for pull-up/pull-down configuration
    enum class PullMode {
        NOPULL,
        PULLUP,
        PULLDOWN
    };

    // Constructor
    GPIO(GPIO_TypeDef* port, uint16_t pin);

    // Method to initialize the pin with direction and pull mode
    void init(Direction direction, PullMode pull);

    // Method to set the pin's state (high/low)
    void write(bool state);

    // Method to read the pin's state
    bool read() const;

private:
    GPIO_TypeDef* port_;
    uint16_t pin_;
};

#endif // GPIO_H
