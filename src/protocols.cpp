#include "protocols.h"
#include "i2c_manager.h"
#include "spi_manager.h"
//#include "i2s_manager.h"
#include "logging.h"

void initializeProtocols() {
    initializeI2C();
    initializeSPI();
 //   initializeI2S();

    logMessage(LOG_LEVEL_INFO, "Communication protocols initialized.");
}
