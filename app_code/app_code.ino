#include<SoftwareSerial.h>

SoftwareSerial BTserial(0,1);   //RX and TX

int flag = 5;
                   
String data1 = "100 84 1582 82 26.92 44 0.369";
String data2 = "99 85 1657 37 9.29 36 0.278";
String data3 = "99 83 2326 20 32.59 41 0.373";
String data4 = "101 89 1741 61 16.09 41 0.322";
String data5 = "100 85 1970 30 5.79 40 0.263";

String data6 = "95.57697447 102.9505734 5273.422264 20.86436117 69.91090136 67.0854193 0.717417257";
String data7 = "95.29771619 109.173671 4641.030346 56.37852603 55.5486384 33.30703297 0.720794854";
String data8 = "96.86771675 101.0369771 4714.419749 37.66176942 66.89172384 19.259155 0.919550085";
String data9 = "96.49999507 104.4678611 4448.257524 64.59677932 59.59896043 31.56277981 0.610496836";
String data10 = "96.11490583 109.8962564 3565.196403 66.58616576 57.66038318 12.05468241 0.761498981";

String anomaly[5] = {data6,data7,data8,data9,data10};
String normal[5]  = {data1,data2,data3,data4,data5};   

void setup() 
{
  // put your setup code here, to run once:
  BTserial.begin(9600);
  pinMode(flag,INPUT);
}


void loop() 
{
  // put your main code here, to run repeatedly:
int choice = digitalRead(flag);
if(BTserial.available())
{
  if(choice==LOW)
  {
    int randNumber = random(0, 5);
    if(randNumber == 0)
      BTserial.println(data1);
    else if(randNumber == 1)
      BTserial.println(data2); 
    else if(randNumber == 2)
      BTserial.println(data3);
    else if(randNumber == 3)
      BTserial.println(data4); 
    else
      BTserial.println(data5);  
  }

  else
  {
    int randNumber = random(0, 5);
    if(randNumber == 0)
      BTserial.println(data6);
    else if(randNumber == 1)
      BTserial.println(data7); 
    else if(randNumber == 2)
      BTserial.println(data8);
    else if(randNumber == 3)
      BTserial.println(data9); 
    else
      BTserial.println(data10);  
  }
}


delay(2000);
}
