#ifndef GPIO_EXPANDER_H
#define GPIO_EXPANDER_H

#include <MCP23S17.h>

extern MCP23S17 mcp;

// Function to setup the GPIO expander
void setupGPIOexpander();

// Function to read from a specific GPIO pin on the expander
uint8_t readGPIOpin(uint8_t pin);

// Function to write to a specific GPIO pin on the expander
void writeGPIOpin(uint8_t pin, uint8_t value);

#endif
