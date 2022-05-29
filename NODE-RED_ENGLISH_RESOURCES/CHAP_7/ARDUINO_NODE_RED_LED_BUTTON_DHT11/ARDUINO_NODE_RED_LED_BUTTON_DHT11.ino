#include <dht.h>
#include <FlexiTimer2.h>
dht DHT;

#define DHT11_PIN 4
#define LED1_PIN 10
#define LED2_PIN 11
#define LED3_PIN 12
#define BUTTON_PIN 2

bool flag=0;

void flash()
{
  byte in_button=digitalRead(BUTTON_PIN);
  if (in_button==0 && flag==0)
  {
  Serial.println(200);  
  flag=1; 
  delay(100);
  }
  if (in_button==1 && flag==1)
  {
  Serial.println(300);  
  flag=0; 
  delay(100);
  }
  
if (Serial.available())
{
  char in_byte=Serial.read();

  switch (in_byte)
  {
    case '1':    digitalWrite(LED1_PIN,1);    break;
    case '2':    digitalWrite(LED1_PIN,0);    break;
    case '3':    digitalWrite(LED2_PIN,1);    break;
    case '4':    digitalWrite(LED2_PIN,0);    break;
    case '5':    digitalWrite(LED3_PIN,1);    break;
    case '6':    digitalWrite(LED3_PIN,0);    break;    
  }
}
}

void setup()
{
  Serial.begin(57600);
pinMode(LED1_PIN,OUTPUT);
pinMode(LED2_PIN,OUTPUT);
pinMode(LED3_PIN,OUTPUT);
pinMode(BUTTON_PIN,INPUT_PULLUP);
  FlexiTimer2::set(20, flash); 
  FlexiTimer2::start();
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    break;
    case DHTLIB_ERROR_CONNECT:
    break;
    case DHTLIB_ERROR_ACK_L:
    break;
    case DHTLIB_ERROR_ACK_H:
    break;
    default: 
    break;
  }
  
  Serial.print(DHT.humidity, 1);
  Serial.print(",");
  Serial.print(DHT.temperature, 1);
  Serial.print("\n");
  delay(3000);
}
