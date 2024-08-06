#define echo_pin 7
#define trig_pin 6

long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin, LOW);
  delay(200);
  digitalWrite(trig_pin, HIGH);
  delay(1000);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin , HIGH);
  distance = duration * 0.034 /2;
  Serial.print("Distance is ");
  Serial.println(distance);

}
