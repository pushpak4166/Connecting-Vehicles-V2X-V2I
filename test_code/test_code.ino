#include<SoftwareSerial.h>

SoftwareSerial BTserial(0,1);   //RX and TX
void setup() {
  // put your setup code here, to run once:
  BTserial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTserial.available())
  {
    BTserial.print("Hello");
  }
  delay(1000);
}
