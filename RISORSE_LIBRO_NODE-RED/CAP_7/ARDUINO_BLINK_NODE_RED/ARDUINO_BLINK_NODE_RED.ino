#define LED_PIN 13
int in_byte =0;

void setup()
{
Serial.begin(57600);
pinMode(LED_PIN,OUTPUT);
}

void loop()
{
if (Serial.available())

in_byte = Serial.read();

if (in_byte== '1') digitalWrite(LED_PIN,1);
if (in_byte== '0') digitalWrite(LED_PIN,0);

}
