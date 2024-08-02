#ifndef MULTIPLEXER_H
#define MULTIPLEXER_H

#include <Arduino.h>
#include <HC4051.h>  // Include the HC4051 library

void initializeMultiplexer();
void selectMultiplexerChannel(uint8_t channel);

#endif
