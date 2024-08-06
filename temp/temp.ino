// C++ code
//
#define LED_BUILTIN_1 9
#define LED_BUILTIN_2 3
int bright_1=5;
int bright_2=255;

void setup()
{
  pinMode(LED_BUILTIN_1, OUTPUT);
  pinMode(LED_BUILTIN_2, OUTPUT);
  }

void loop()
{
  analogWrite(LED_BUILTIN_1, bright_1);
  analogWrite(LED_BUILTIN_2, bright_2);
} 