int input_value=0;
void setup(){
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);

  
}
void pattern(){
    digitalWrite(12,HIGH);
  delay(100);
  digitalWrite(11,HIGH);
  delay(100);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(9,HIGH);
  delay(100);

  digitalWrite(12,LOW);
  delay(100);
  digitalWrite(11,LOW);
  delay(100);
  digitalWrite(10,LOW);
  delay(100);
  digitalWrite(9,LOW);
  delay(100);

  digitalWrite(12,HIGH);
  delay(100);
  digitalWrite(11,HIGH);
  delay(100);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(9,HIGH);
  delay(100);

  digitalWrite(12,LOW);
  delay(100);
  digitalWrite(11,LOW);
  delay(100);
  digitalWrite(10,LOW);
  delay(100);
  digitalWrite(9,LOW);
  delay(100);
  digitalWrite(12,HIGH);
  delay(100);
  digitalWrite(11,HIGH);
  delay(100);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(9,HIGH);
  delay(100);

  digitalWrite(12,LOW);
  delay(100);
  digitalWrite(11,LOW);
  delay(100);
  digitalWrite(10,LOW);
  delay(100);
  digitalWrite(9,LOW);
  delay(100);

}
void logic(int i){
  pattern();
  switch(i){
  case 1:
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    break;
case 2:
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    break;
case 3:
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    break;
case 4:
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    break;
case 5:
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    break;
case 6:
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    break;
case 7:
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    break;
case 8:
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    break;
case 9:
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    break;
case 10:
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    break;
case 11:
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    break;
case 12:
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    break;
case 13:
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    break;
case 14:
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    break;
case 15:
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    break;
  default:
        digitalWrite(12,LOW);
        digitalWrite(11,LOW);
        digitalWrite(10,LOW);
        digitalWrite(9,LOW);
  }
}
void loop(){
  if(Serial.available()>0){
    input_value=Serial.readStringUntil('\n').toInt();
    if(input_value > 0 && input_value < 16){
      logic(input_value);
    }
  }


}