#ifndef VISUALIZATION_H
#define VISUALIZATION_H

void connectToWiFi();
void processAndSendData(float humidity, float proximity, float light, float temperature, float audio, float motion, float pressure);

#endif
