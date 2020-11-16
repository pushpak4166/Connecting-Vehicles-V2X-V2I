const int flag = 5;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(flag,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int inp = digitalRead(flag);
  Serial.println(inp);
  delay(500);
}
