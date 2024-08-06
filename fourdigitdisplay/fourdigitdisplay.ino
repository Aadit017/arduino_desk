#include <TM1637Display.h>

// Define the connections pins
#define CLK_PIN 2
#define DIO_PIN 3
const uint8_t COLON = 0x80;
uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };

// Create an instance of the TM1637Display class
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  display.setBrightness(5);
  
}

void loop() {
  // for(int i=0;i<10000;i+=1){
  //   display.showNumberDecEx(i,COLON,true);
  //   delay(1000);
  // }
  // display.setBrightness(0x0f);

  // // All segments on
  // display.setSegments(data);
  // delay(500);
  // display.setSegments(blank);
  uint8_t addColon = display.encodeDigit(0x80) | 0x80 ; // setting bit 7 enables the colon         
  display.setSegments(&addColon,1,1); 
  display.showNumberDecEx(12,COLON,true);
}
