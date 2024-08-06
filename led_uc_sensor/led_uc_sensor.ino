// very basic program that'll turn on the led as soon as the distance shown on the ultrasonic sensor goes to below 40
#define echo_pin 4
#define trig_pin 5
#define led_pin 13 
long duration;
int distance;
int state = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led_pin,state);
  digitalWrite(trig_pin , LOW);
  delay(20);
  digitalWrite(trig_pin , HIGH);
  delay(100);
  digitalWrite(trig_pin , LOW);
  duration = pulseIn(echo_pin , HIGH);
  distance = duration * 0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance < 200){
    state=HIGH;
  }else{
    state=LOW;
  }
}
