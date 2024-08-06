#include <TM1637Display.h>
#define btn1_read 2
#define btn2_read 5
#define btnMain_read 6
#define clk_pin 3
#define dio_pin 4
#define led1_pin 7
#define led2_pin 8
TM1637Display clock(clk_pin, dio_pin);
const uint8_t clock_on[] = { 0xff, 0xff, 0xff, 0xff };
const uint8_t clock_off[] = { 0x00, 0x00, 0x00, 0x00 };
int count = 0;
int btn1_state;
int btn2_state;
int btnMain_state;
int prev_btn1_state = LOW;
int prev_btn2_state = LOW;
int prev_btnMain_state = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;
uint8_t timer = 30;
uint8_t points = 0;
bool condition = true; // responsible for ensuring the game is running or not 
void setup() {
  clock.setBrightness(7);
  pinMode(btn1_read, INPUT);
  pinMode(btn2_read, INPUT);
  pinMode(btnMain_read, INPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  Serial.begin(9600);
  clock.setSegments(clock_on);
}

void loop() {
  digitalWrite(led1_pin, HIGH);
  digitalWrite(led2_pin, HIGH);
  btn1_state = digitalRead(btn1_read);
  btn2_state = digitalRead(btn2_read);
  btnMain_state = digitalRead(btnMain_read);

  if (btn1_state == HIGH && prev_btn1_state == LOW) {
    Serial.println("Button 1");
    delay(10);
  }
  if (btn2_state == HIGH && prev_btn2_state == LOW) {
    Serial.println("Button 2");
    delay(10);
  }
  if (btnMain_state == HIGH && prev_btnMain_state == LOW) {
    Serial.println("Button 3");
    delay(10);
  }

  prev_btn1_state = btn1_state;
  prev_btn2_state = btn2_state;
  prev_btnMain_state = btnMain_state;

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (timer > 0) {
      timer -= 1;
    }

    uint8_t min = timer / 60;
    uint8_t sec = timer % 60;
    uint8_t display[4];
    display[3] = clock.encodeDigit(sec % 10);
    display[2] = clock.encodeDigit(sec / 10);
    display[1] = clock.encodeDigit(min % 10) | 0x80;
    display[0] = clock.encodeDigit(min / 10);
    clock.setSegments(display);
  }

  if (timer == 0) {
    clock.setSegments(clock_on);
    clock.setBrightness(1);
  }
}
