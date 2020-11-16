#include<SoftwareSerial.h>

SoftwareSerial BTserial(0,1);   //RX and TX\

const int flag = 5;


void setup() {
  // put your setup code here, to run once:
  BTserial.begin(9600);
  pinMode(flag,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if(flag)
{
  BTserial.print("1234");
  BTserial.print(",");
  BTserial.print("4321");
  BTserial.print(",");
  BTserial.print("sensor OK");
  BTserial.print(";");  
}
else
{
  BTserial.print("9999");
  BTserial.print(",");
  BTserial.print("8888");
  BTserial.print(",");
  BTserial.print("NOT OK");
  BTserial.print(";");   
}
delay(300);
}
