#include "Wire.h" // To communicate with I2C devices.

////////
#include<SoftwareSerial.h>
SoftwareSerial BTserial(0,1);   //RX and TX

const int MPU_ADDR = 0x68; // I2C address of the MPU-6050

int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data

char tmp_str[7]; // temporary variable used in convert function

char* convert_int16_to_str(int16_t i) { // converts int16 to string
  sprintf(tmp_str, "%d", i);
  return tmp_str;
}

void setup() {
  //Serial.begin(9600);
  BTserial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  
}
void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
  
  accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  temperature = Wire.read()<<8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)


  BTserial.print(convert_int16_to_str(accelerometer_x));
  BTserial.print(","); BTserial.print(convert_int16_to_str(accelerometer_y));
  BTserial.print(","); BTserial.print(convert_int16_to_str(accelerometer_z));
  BTserial.print(","); BTserial.print(temperature/340.00+36.53);
  BTserial.print(","); BTserial.print(convert_int16_to_str(gyro_x));
  BTserial.print(","); BTserial.print(convert_int16_to_str(gyro_y));
  BTserial.print(","); BTserial.print(convert_int16_to_str(gyro_z));
  BTserial.println();  

//  // print data
//  Serial.print(convert_int16_to_str(accelerometer_x));
//  Serial.print(","); Serial.print(convert_int16_to_str(accelerometer_y));
//  Serial.print(","); Serial.print(convert_int16_to_str(accelerometer_z));
//  Serial.print(","); Serial.print(temperature/340.00+36.53);
//  Serial.print(","); Serial.print(convert_int16_to_str(gyro_x));
//  Serial.print(","); Serial.print(convert_int16_to_str(gyro_y));
//  Serial.print(","); Serial.print(convert_int16_to_str(gyro_z));
//  Serial.println();
  
  // delay
  delay(200);
}
