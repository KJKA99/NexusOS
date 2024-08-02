#include "gpio_expander.h"
#include <Wire.h>
#include "logging.h"

Adafruit_MCP23X17 mcp;

void initializeGPIOExpander() {
    if (!mcp.begin_I2C()) {
        logMessage(LOG_LEVEL_ERROR, "Failed to initialize MCP23S17 GPIO expander!");
        while (1) delay(10);
    }

    // Example setup for additional GPIO pins
    for (int i = 0; i < 16; i++) {
        mcp.pinMode(i, OUTPUT);
        mcp.digitalWrite(i, LOW);
    }

    logMessage(LOG_LEVEL_INFO, "MCP23S17 GPIO expander initialized.");
}
