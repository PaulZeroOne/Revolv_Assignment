# Revolv_Assignment

## `GPIO.h`

This file contains the class definition and declarations for the `GPIO` class. The purpose of each section is described below:

### Includes and Enums

- **`#include "stm32f4xx_hal.h"`**: This includes the STM32 HAL library, which provides the necessary functions and definitions for GPIO control.
- **Enums for Direction and Pull Mode**:
  - `Direction`: Defines the pin direction as either `INPUT` or `OUTPUT`.
  - `PullMode`: Defines the internal resistor configuration for the pin (`NOPULL`, `PULLUP`, `PULLDOWN`).

### GPIO Class

The `GPIO` class provides the interface for configuring and controlling a GPIO pin.

- **Constructor**: `GPIO(GPIO_TypeDef* port, uint16_t pin);`
  - Initializes the GPIO object with a specific port (e.g., `GPIOA`, `GPIOB`) and pin number.
  
- **Public Methods**:
  - `void init(Direction direction, PullMode pull);`: Configures the pin's direction (input/output) and pull mode (no pull-up/down, pull-up, or pull-down).
  - `void write(bool state);`: Sets the GPIO pin to high or low state.
  - `bool read() const;`: Reads the current state of the GPIO pin.

- **Private Members**:
  - `GPIO_TypeDef* port_`: Stores the port (e.g., GPIOA).
  - `uint16_t pin_`: Stores the pin number (e.g., GPIO_PIN_0).

---

## `GPIO.cpp`

This file contains the implementation of the `GPIO` class methods declared in `GPIO.h`.

### Constructor

- **`GPIO::GPIO(GPIO_TypeDef* port, uint16_t pin)`**:
  - Initializes the port and pin for a specific GPIO instance, allowing methods to operate on the assigned port/pin combination.

### Method Implementations

- **`void GPIO::init(Direction direction, PullMode pull)`**:
  - Creates a `GPIO_InitTypeDef` structure to define the pin's configuration.
  - Sets the pin mode based on the `direction` parameter:
    - `GPIO_MODE_INPUT` for input mode.
    - `GPIO_MODE_OUTPUT_PP` for push-pull output mode.
  - Configures the pull-up/pull-down resistors based on the `pull` parameter:
    - `GPIO_NOPULL`, `GPIO_PULLUP`, or `GPIO_PULLDOWN`.
  - Calls `HAL_GPIO_Init` to apply the configuration to the hardware.

- **`void GPIO::write(bool state)`**:
  - Uses `HAL_GPIO_WritePin` to set the pin to `GPIO_PIN_SET` (high) if `state` is `true` and `GPIO_PIN_RESET` (low) if `false`.

- **`bool GPIO::read() const`**:
  - Reads the pin state using `HAL_GPIO_ReadPin`.
  - Returns `true` if the pin is high (`GPIO_PIN_SET`) and `false` if low (`GPIO_PIN_RESET`).

---
