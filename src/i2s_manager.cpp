/*#include "i2s_manager.h"
#include "multiplexer.h"  // Include multiplexer header
#include "logging.h"

#define I2S_NUM_0 (i2s_port_t)0
#define I2S_NUM_1 (i2s_port_t)1

void initializeI2S(I2SBusConfig config) {
    int i2s_num = (config == I2SBusConfig::MASTER_RX0 || config == I2SBusConfig::MASTER_TX0) ? I2S_NUM_0 : I2S_NUM_1;
    bool isRX = (config == I2SBusConfig::MASTER_RX0 || config == I2SBusConfig::MASTER_RX1);

    i2s_config_t i2s_config = {
        .mode = isRX ? (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX) : (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S_MSB,
        .intr_alloc_flags = 0,  // Use default interrupt allocation
        .dma_buf_count = 8,
        .dma_buf_len = 64,
        .use_apll = false,
        .tx_desc_auto_clear = isRX ? false : true,  // Only auto-clear for transmitter
        .fixed_mclk = 0
    };

    i2s_driver_install((i2s_port_t)i2s_num, &i2s_config, 0, NULL);

    // Pin configuration tailored for each bus
    i2s_pin_config_t pin_config = {
        .bck_io_num = (i2s_num == I2S_NUM_0) ? 26 : 14,
        .ws_io_num = (i2s_num == I2S_NUM_0) ? 25 : 13,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num = (i2s_num == I2S_NUM_0) ? 33 : 34
    };
    i2s_set_pin((i2s_port_t)i2s_num, &pin_config);
    i2s_zero_dma_buffer((i2s_port_t)i2s_num);

    logMessage(LOG_LEVEL_INFO, String("I2S bus ") + i2s_num + " initialized as " + (isRX ? "RX" : "TX"));
}

void selectI2SDevice(uint8_t bus, uint8_t channel) {
    if (bus == 0) {
        selectMultiplexerChannel(channel);
    } else if (bus == 1) {
        // For the second bus, use a different multiplexer if necessary or extend the multiplexer logic
        selectMultiplexerChannel(channel + 4); // Example logic, adjust as needed
    }
    logMessage(LOG_LEVEL_DEBUG, "I2S device selected on bus " + String(bus) + ", channel " + String(channel));
}

float readI2SData() {
    int16_t i2s_read_buff[64];
    size_t bytes_read;
    i2s_read(I2S_NUM_0, &i2s_read_buff, sizeof(i2s_read_buff), &bytes_read, portMAX_DELAY);
    return (float)i2s_read_buff[0];
}

I2SDeviceType identifyI2SDevice(uint8_t bus, uint8_t channel) {
    selectI2SDevice(bus, channel);

    // Use a known signal pattern or test read to differentiate between devices
    float sample = readI2SData();

    // For simplicity, we assume that an amplifier will output a higher value than a microphone in our test scenario
    if (sample > 1000) {
        logMessage(LOG_LEVEL_INFO, "I2S device identified as AMPLIFIER on bus " + String(bus) + ", channel " + String(channel));
        return I2S_DEVICE_AMPLIFIER;
    } else if (sample <= 1000) {
        logMessage(LOG_LEVEL_INFO, "I2S device identified as MICROPHONE on bus " + String(bus) + ", channel " + String(channel));
        return I2S_DEVICE_MICROPHONE;
    }

    logMessage(LOG_LEVEL_WARN, "I2S device identification failed on bus " + String(bus) + ", channel " + String(channel));
    return I2S_DEVICE_UNKNOWN;
}
*/