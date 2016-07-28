#include <FastGPIO.h>
#define APA102_USE_FAST_GPIO
#include <APA102.h>

const uint8_t dataPin = 11;
const uint8_t clockPin = 12;
APA102<dataPin, clockPin> ledStrip;
int counter = 0;
const uint16_t ledCount = 60;
rgb_color colors[ledCount];
void setup() {
uint8_t time = millis() >> 2;
for(uint16_t i = 0; i < ledCount; i++)
{
  uint8_t x = time - i * 8;
  colors[i].red = x;
  colors[i].green = 255 - x;
  colors[i].blue = x;
}
ledStrip.write(colors, ledCount, 31);

}

void loop() {
 ledStrip.startFrame();
for(uint16_t i = 0; i < ledCount; i++)
{
  ledStrip.sendColor(255, 8, 10, ledCount-i/2);
    delay(1000);
}
ledStrip.endFrame(ledCount);

}
