const int gasSensorPin = A0; 
//.................................................................................................................... 
const int irSensorPin = 2; 
const int eyeSensorPin = 6; 
//................................................................................. 
int motorSpeed; 
//................................................................................. 
#include <OneWire.h> 
#include <DallasTemperature.h> 
#define ONE_WIRE_BUS 8 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire); 
float temperatureC; 
//................................................................................. 
#define buzzer 7 
//................................................................................ 
#include <Wire.h> 
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h> 
Adafruit_ADXL345_Unified accel = 
Adafruit_ADXL345_Unified(12345);  // 12345 is the sensor's I2C 
address 
int ac = 1; 
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
#include "HX711.h" 
const int HX711_DOUT_PIN = 3;  // Connect DOUT pin to Arduino 
digital pin 2 
const int HX711_SCK_PIN = 4;   // Connect SCK pin to Arduino digital 
pin 3 
HX711 pressureSensor; 
//................................................................................................. 
#include <SoftwareSerial.h> 
SoftwareSerial Gsm(6,5); 
char phone_no[] = "+919527426993";  //replace with phone no. to get 
sms 
//.................................................................................... 
#include <TinyGPS.h> 
TinyGPS gps;  //Creates a new instance of the TinyGPS object 
int state; 
String textMessage;  
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
const int potPin = A0;    // Analog input pin for potentiometer 
const int motorPin = 10;   // PWM pin for motor control 
const int motorPin1 = 9; 
const int motorPin2 = 7; 
#define buzzer 13 
/////////////////////////////////////////////////////////////////// 
void setup() { 
  Serial.begin(9600); 
 pinMode(motorPin, OUTPUT); 
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT); 
  pinMode(gasSensorPin, INPUT); 
//.................................................................................................................... 
  pinMode(irSensorPin, INPUT); 
  pinMode(eyeSensorPin, INPUT); 
  //............................................................................. 
  pinMode(buzzer, OUTPUT); 
  //............................................................................ 
  Serial.println("Adafruit ADXL345 test!"); 
  if (!accel.begin()) { 
    Serial.println("Could not find a valid ADXL345 sensor, check 
wiring!"); 
    while (1) 
      ; 
  } 
  accel.setRange(ADXL345_RANGE_16_G); 
  //....................................................................... 
 digitalWrite(motorPin1,LOW); 
 digitalWrite(motorPin2,LOW); 
  Gsm.begin(9600); 
  pressureSensor.begin(HX711_DOUT_PIN, HX711_SCK_PIN); 
  sensors.begin(); 
  //..............................................................................    
  } 
void loop() { 
  int gasSensorValue = digitalRead(gasSensorPin); 
  digitalWrite(buzzer, HIGH); 
  delay(100); 
  digitalWrite(buzzer, LOW); 
  if (gasSensorValue == HIGH) { 
    Serial.println("Alcohol NOT Dtected"); 
    delay(1000); 
    while (1) { 
      delay(2000); 
      int irSensorValue = digitalRead(irSensorPin); 
      if (irSensorValue == LOW) { 
        digitalWrite(buzzer, HIGH); 
        delay(100); 
        digitalWrite(buzzer, LOW); 
        Serial.println("Seat belt   Detected"); 
       stop(); 
        delay(2000); 
        while (1) { 
          int eyeSensorValue = digitalRead(eyeSensorPin); 
          if (eyeSensorValue == LOW) { 
            Serial.println("eye not blink  "); 
           
            temp(); 
            if (temperatureC < 50) { 
              Serial.println("Temp ok"); 
              long pressureValue = pressureSensor.read(); 
              Serial.println(pressureValue); 
              if (pressureValue <= 100000) { 
                char a = "OK"; 
                Serial.println("pressure ok"); 
                speed(); 
                  Serial.println("Car Started "); 
                accident(); 
                }  
                else { 
                Serial.println("pressure HIGH"); 
                digitalWrite(buzzer, HIGH); 
                delay(500); 
                digitalWrite(buzzer, LOW); 
                stop(); 
              } 
            } 
            else { 
              Serial.print("Temp HIGH"); 
              digitalWrite(buzzer, HIGH); 
              delay(500); 
              digitalWrite(buzzer, LOW); 
              stop(); 
            } 
          }  
else { 
            Serial.println("eye blink"); 
            digitalWrite(buzzer, HIGH); 
            delay(500); 
            digitalWrite(buzzer, LOW); 
           stop(); 
          } 
        } 
      }  
        else { 
        Serial.println("Seat belt  NOT  Dtected"); 
        digitalWrite(buzzer, HIGH); 
        delay(500); 
        digitalWrite(buzzer, LOW); 
        stop(); 
      } 
    } 
  }  
    else { 
    Serial.println("Alcohol  Detected "); 
    digitalWrite(buzzer, HIGH); 
    delay(500); 
    digitalWrite(buzzer, LOW); 
    stop(); 
  } 
  delay(1000); 
} 
void temp() { 
  sensors.requestTemperatures(); 
  // Get the temperature in degrees Celsius 
  temperatureC = sensors.getTempCByIndex(0); 
  // Check if reading is valid (nonzero) 
  if (temperatureC != DEVICE_DISCONNECTED_C) { 
    // Print the temperature to the Serial Monitor 
    Serial.print("Temperature: "); 
    Serial.print(temperatureC); 
    Serial.println(" °C"); 
  } else { 
    Serial.println("Error: Unable to read temperature"); 
  } 
  delay(1000); 
} 
void accident() { 
  sensors_event_t event; 
  accel.getEvent(&event); 
  //Serial.print("X: "); 
  //Serial.print(event.acceleration.x); 
 //// Serial.print("  "); 
 // Serial.print("Y: "); 
 // Serial.print(event.acceleration.y); 
 // Serial.print("  "); 
//Serial.print("Z: "); 
  Serial.print(event.acceleration.z); 
 // Serial.println("  "); 
  if (event.acceleration.x < -5 || event.acceleration.x > 5 || 
event.acceleration.y < -5 || event.acceleration.y > 5) { 
    Serial.print("Accsident detected"); 
    textMessage = "High Level Accsident detected"; 
    stop(); 
    digitalWrite(buzzer, HIGH); 
    delay(500); 
    digitalWrite(buzzer, LOW); 
    Send_sms(); 
    delay(1000); 
  } 
  else { 
    Serial.println("Accsident not detected "); 
  } 
  delay(1000); 
} 
void Send_sms() { 
  Serial.println("Sending Live Location"); 
  bool newData = false; 
  unsigned long chars; 
  unsigned short sentences, failed; 
  // For one second we parse GPS data and report some key values 
  for (unsigned long start = millis(); millis() - start < 1000;) { 
    while (Serial.available()) { 
      char c = Serial.read(); 
      Serial.print(c); 
      if (gps.encode(c)) 
        newData = true; 
    } 
  } 
  float flat, flon; 
  unsigned long age; 
  gps.f_get_position(&flat, &flon, &age); 
  Gsm.print("AT+CMGF=1\r"); 
  delay(400); 
  Gsm.print("AT+CMGS=\""); 
  Gsm.print(phone_no); 
  Gsm.println("\""); 
  delay(3000); 
  Gsm.print("motorSpeed="); 
  Gsm.println(motorSpeed); 
  Gsm.print("http://maps.google.com/maps?q=loc:"); 
  Gsm.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6); 
  Gsm.print(","); 
  Gsm.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 
6); 
  delay(200); 
  Gsm.println((char)26);  // End AT command with a ^Z, ASCII code 26 
delay(200); 
Gsm.println(); 
delay(1000); 
Serial.print("location Sent"); 
delay(3000); 
delay(60000); 
} 
void speed(){ 
digitalWrite(motorPin1,HIGH); 
digitalWrite(motorPin2,LOW); 
// Read the value from the potentiometer 
int potValue = analogRead(potPin); 
// Map the potentiometer value to the range923f  of motor speed 
motorSpeed = map(potValue, 0, 1023, 0, 255); 
// Control the motor speed using PWM 
analogWrite(motorPin, motorSpeed); 
// Print the potentiometer value and motor speed 
// Serial.print("Potentiometer Value: "); 
//Serial.print(potValue); 
Serial.print("    Motor Speed: "); 
Serial.println(motorSpeed); 
} 
void stop(){ 
digitalWrite(motorPin1,LOW); 
digitalWrite(motorPin2,LOW); 
}