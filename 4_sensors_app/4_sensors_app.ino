#include<SoftwareSerial.h>

SoftwareSerial BTserial(0,1);   //RX and TX

int s1 = 5;    // Sensors 
int s2 = 6;
int s3 = 7;
int s4 = 8;
int curr = 0;
                   
String data0_0 = "46  85.44977631 20.57592286 27.55706515";
String data0_1 = "63  86.10856647 19.93676696 21.19632587";
String data0_2 = "36  89.39946762 28.31913852 23.16067123";

String data1_0 = "62  82.75814794 26.45204058 79.20195568";
//String data1_1 = "47  88.52176567 26.8231615  63.82147423";
//String data1_2 = "54  88.60721353 17.75561756 62.21602005";

String data2_0 = "67  87.08314959 72.49208633 24.53163913";
//String data2_1 = "72  83.38017666 69.4697486  15.56504534";
//String data2_2 = "73  85.01185461 47.81857801 20.10676464";

String data3_0 = "49  87.09957531 47.08866044 79.00454677";
//String data3_1 = "64  89.54787607 75.03105529 87.9200138";
//String data3_2 = "35  84.90468289 84.7431339  55.12706331";

String data4_0 = "43  116.0559036 25.20184191 27.2684978";
//String data4_1 = "66  120.1409636 14.61534714 17.95134084";
//String data4_2 = "70  114.3984985 11.02810957 27.90569317";

String data5_0 = "62  120.916964  24.13268871 77.75612383";
//String data5_1 = "38  95.00266955 21.69670662 89.22308609";
//String data5_2 = "59  128.1387981 19.46766459 82.63455681";

String data6_0 = "59  118.8445906 50.40595925 23.10262001";
//String data6_1 = "46  118.4352344 40.73891753 26.76231689";
//String data6_2 = "53  121.5422375 81.45281565 29.04558776";

String data7_0 = "36  129.7972069 58.67385785 56.39809255";
//String data7_1 = "63  128.2066086 66.26177723 83.03635897";
//String data7_2 = "55  119.0305885 55.65209191 67.46299137";

String data8_0 = "99  83.78924052 20.7874538  24.75274312";
//String data8_1 = "89  80.08893536 20.55269257 23.31095968";
//String data8_2 = "97  80.52867446 29.86268853 20.09706967";

String data9_0 = "85  89.53662764 17.95072355 80.08551981";
//String data9_1 = "95  88.0757432  11.09845075 72.3960364";
//String data9_2 = "88  82.58415821 11.7788154  59.60725243";

String data10_0 = "95 89.87114694 57.07736182 27.66077676";
//String data10_1 = "83 88.24529107 81.78558347 18.8810075";
//String data10_2 = "93 80.68442105 70.8001129  21.41403663";

String data11_0 = "90 82.62664324 75.19609566 76.67884656";
//String data11_1 = "89 83.49393733 68.9233862  81.87599145";
//String data11_2 = "82 89.78906565 47.99703256 70.72635222";

String data12_0 = "93 101.3497246 11.64994037 18.69586403";
//String data12_1 = "82 123.9817584 12.48766637 20.62463877";
//String data12_2 = "85 106.4481044 23.47617712 22.38646956";

String data13_0 = "90 103.0416638 18.42712816 80.11837373";
//String data13_1 = "96 119.4381046 14.67778901 75.98452784";
//String data13_2 = "98 104.5934108 18.87802848 68.05065679";

String data14_0 = "96 123.9053238 42.56422736 18.85439688";
//String data14_1 = "87 114.9822281 45.78742308 15.03931658";
//String data14_2 = "92 114.1557093 80.96199273 17.62912833";

String data15_0 = "95 100.9513395 71.28966878 86.59644579";
//String data15_1 = "93 96.44341833 77.51801681 85.6627027";
//String data15_2 = "89 113.4301197 47.90233776 71.57467721";


void setup() 
{
    // put your setup code here, to run once:
    pinMode(s1,INPUT);
    pinMode(s2,INPUT);
    pinMode(s3,INPUT);
    pinMode(s4,INPUT);
    BTserial.begin(9600);
}


void loop() 
{
    // put your main code here, to run repeatedly:
    curr = 0;
    if(digitalRead(s1))
    curr = curr | 1;
    if(digitalRead(s2))
    curr = curr | 2;
    if(digitalRead(s3))
    curr = curr | 4;
    if(digitalRead(s4))
    curr = curr | 8;
  
    if(BTserial.available())
    {
        if(curr == 0)
        {
          int randNumber = random(0, 3); 
          if(randNumber == 0)
             BTserial.println(data0_0);
          if(randNumber == 1)
             BTserial.println(data0_1); 
          if(randNumber == 2)
             BTserial.println(data0_2);  
        }
        if(curr == 1)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data1_0);
//          if(randNumber == 1)
//             BTserial.println(data1_1); 
//          if(randNumber == 2)
//             BTserial.println(data1_2);  
        }
        if(curr == 2)
        {
//          int randNumber = random(0, 3);
//          if(randNumber == 0)
             BTserial.println(data2_0);
//          if(randNumber == 1)
//             BTserial.println(data2_1); 
//          if(randNumber == 2)
//             BTserial.println(data2_2);   
        }
        if(curr == 3)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data3_0);
//          if(randNumber == 1)
//             BTserial.println(data3_1); 
//          if(randNumber == 2)
//             BTserial.println(data3_2);   
        }
        if(curr == 4)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data4_0);
//          if(randNumber == 1)
//             BTserial.println(data4_1); 
//          if(randNumber == 2)
//             BTserial.println(data4_2);  
        }
        if(curr == 5)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data5_0);
//          if(randNumber == 1)
//             BTserial.println(data5_1); 
//          if(randNumber == 2)
//             BTserial.println(data5_2);  
        }
        if(curr == 6)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data6_0);
//          if(randNumber == 1)
//             BTserial.println(data6_1); 
//          if(randNumber == 2)
//             BTserial.println(data6_2);  
        }
        if(curr == 7)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data7_0);
//          if(randNumber == 1)
//             BTserial.println(data7_1); 
//          if(randNumber == 2)
//             BTserial.println(data7_2);   
        }
        if(curr == 8)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data8_0);
//          if(randNumber == 1)
//             BTserial.println(data8_1); 
//          if(randNumber == 2)
//             BTserial.println(data8_2);   
        }
        if(curr == 9)
        {
//          int randNumber = random(0, 3);
//          if(randNumber == 0)
             BTserial.println(data9_0);
//          if(randNumber == 1)
//             BTserial.println(data9_1); 
//          if(randNumber == 2)
//             BTserial.println(data9_2);  
        }
        if(curr == 10)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data10_0);
//          if(randNumber == 1)
//             BTserial.println(data10_1); 
//          if(randNumber == 2)
//             BTserial.println(data10_2);  
        }
        if(curr == 11)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data11_0);
//          if(randNumber == 1)
//             BTserial.println(data11_1); 
//          if(randNumber == 2)
//             BTserial.println(data11_2);   
        }
        if(curr == 12)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data12_0);
//          if(randNumber == 1)
//             BTserial.println(data12_1); 
//          if(randNumber == 2)
//             BTserial.println(data12_2);   
        }
        if(curr == 13)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data13_0);
//          if(randNumber == 1)
//             BTserial.println(data13_1); 
//          if(randNumber == 2)
//             BTserial.println(data13_2);   
        }
        if(curr == 14)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data14_0);
//          if(randNumber == 1)
//             BTserial.println(data14_1); 
//          if(randNumber == 2)
//             BTserial.println(data15_2);   
        }
        if(curr == 15)
        {
//          int randNumber = random(0, 3); 
//          if(randNumber == 0)
             BTserial.println(data15_0);
//          if(randNumber == 1)
//             BTserial.println(data15_1); 
//          if(randNumber == 2)
//             BTserial.println(data15_2);  
        }
        
    }
    
delay(2000);

}
