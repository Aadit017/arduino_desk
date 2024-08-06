const int led_pin=11;
void setup() {
  pinMode(led_pin,OUTPUT);
}

void loop() {
for(int b=1;b<=127;b+=1){
  delay(10);
  analogWrite(led_pin,b);
}
for(int b=127;b>=0;b-=1){
  delay(10);
  analogWrite(led_pin,b);
}
}
