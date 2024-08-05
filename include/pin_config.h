// pin_config.h

#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// I2C Pin Definitions
#define I2C_SDA 9
#define I2C_SCL 10

// SPI Pin Definitions
#define SPI_SCK 18
#define SPI_MISO 16
#define SPI_MOSI 17
#define SPI_CS 5 // This can be customized per device

// Multiplexer Control Pins
/*#define MULTIPLEXER_S0 32
#define MULTIPLEXER_S1 33
#define MULTIPLEXER_S2 25*/

/*      GPIO Expander (MCP23S17) pin map         */
#define GPIO_EXPANDER_SPI_CS 48 // GPIO 48 on the ESP32

// GPIO Expander General Purpose Pins
#define GPB0  0 // Gen 42
#define GPB1  1 // Gen 43
#define GPB2  2 // Gen 32
#define GPB3  3 // Gen 33
#define GPB4  4 // Gen 22
#define GPB5  5 // Gen 23
#define GPB6  6 // Gen 12
#define GPB7  7 // Gen 13
#define GPA6  26 // Gen 52
#define GPA7  27 // Gen 53

// GPIO Expander SPI CS Pins
#define GPA0  20 // CS 1
#define GPA1  21 
#define GPA2  22 // ...
#define GPA3  23
#define GPA4  24
#define GPA5  25 // CS 6


#endif // PIN_CONFIG_H
