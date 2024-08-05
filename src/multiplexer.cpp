/*#include "multiplexer.h"
#include <HC4051.h>
#include "logging.h"

// Define the GPIO pins connected to the multiplexer control lines
#define MULTIPLEXER_S0 32
#define MULTIPLEXER_S1 33
#define MULTIPLEXER_S2 25

HC4051 multiplexer(MULTIPLEXER_S0, MULTIPLEXER_S1, MULTIPLEXER_S2);

void initializeMultiplexer() {
    selectMultiplexerChannel(0); // Default to channel 0
    logMessage(LOG_LEVEL_INFO, "Multiplexer initialized.");
}

void selectMultiplexerChannel(uint8_t channel) {
    multiplexer.setChannel(channel);
    logMessage(LOG_LEVEL_DEBUG, ("Multiplexer channel selected: " + String(channel)).c_str());
}
*/