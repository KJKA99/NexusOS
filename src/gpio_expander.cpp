#include "gpio_expander.h"
#include <Wire.h>
#include "logging.h" // log when things happen
#include "pin_config.h" // contains pin configuration/pin map

MCP23S17 mcp(GPIO_EXPANDER_SPI_CS);


void setupGPIOexpander() {
 if (!mcp.begin()) {
        Serial.println("MCP23S17 init failed!");
        while (1);
    }
    
    mcp.pinMode1(GPB0, OUTPUT);
    mcp.pinMode1(GPB1, OUTPUT);
    mcp.pinMode1(GPB2, OUTPUT);
    mcp.pinMode1(GPB3, OUTPUT);
    mcp.pinMode1(GPB4, OUTPUT);
    mcp.pinMode1(GPB5, OUTPUT);
    mcp.pinMode1(GPB6, OUTPUT);
    mcp.pinMode1(GPB7, OUTPUT);

    mcp.pinMode1(GPA0, OUTPUT);
    mcp.pinMode1(GPA1, OUTPUT);
    mcp.pinMode1(GPA2, OUTPUT);
    mcp.pinMode1(GPA3, OUTPUT);
    mcp.pinMode1(GPA4, OUTPUT);
    mcp.pinMode1(GPA5, OUTPUT);
    mcp.pinMode1(GPA6, OUTPUT);
    mcp.pinMode1(GPA7, OUTPUT);

    
    logMessage(LOG_LEVEL_INFO, "GPIO Expander Initializer");
}


uint8_t readGPIOpin (uint8_t pin, uint8_t value) {
   return mcp.read1(pin);

}

void writeGPIOpin (uint8_t pin, uint8_t value) { 
     mcp.write1(pin, value);
}