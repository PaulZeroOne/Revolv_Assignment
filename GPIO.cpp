// GPIO.cpp

#include "GPIO.h"

// Constructor implementation
GPIO::GPIO(GPIO_TypeDef* port, uint16_t pin) : port_(port), pin_(pin) {}

// Initialize the GPIO pin with direction and pull mode
void GPIO::init(Direction direction, PullMode pull) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Set the pin direction
    GPIO_InitStruct.Pin = pin_;
    GPIO_InitStruct.Mode = (direction == Direction::INPUT) ? GPIO_MODE_INPUT : GPIO_MODE_OUTPUT_PP;

    // Set pull-up/pull-down configuration
    GPIO_InitStruct.Pull = (pull == PullMode::PULLUP) ? GPIO_PULLUP :
                           (pull == PullMode::PULLDOWN) ? GPIO_PULLDOWN :
                           GPIO_NOPULL;

    // Set pin speed (default to low frequency for general use)
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    // Initialize the pin with the HAL library function
    HAL_GPIO_Init(port_, &GPIO_InitStruct);
}

// Set the GPIO pin state (true for high, false for low)
void GPIO::write(bool state) {
    HAL_GPIO_WritePin(port_, pin_, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

// Read the GPIO pin state
bool GPIO::read() const {
    return (HAL_GPIO_ReadPin(port_, pin_) == GPIO_PIN_SET);
}
