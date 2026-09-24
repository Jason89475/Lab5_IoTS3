#include <Arduino.h> 

#include <SPI.h> 

#include <SD.h> 

const int chipSelect = 10; 

File dataFile; 

 
const int potPin = A0; 

int sensorValue = 0; 



int position = 0; 

 

void setup() { 

 //Start the SD card 

  Serial.begin(9600); 
//Initialize SD Card
  Serial.println("Program Started"); 

  Serial.println("Initializing SD Card..."); 

  if (SD.begin(chipSelect)) { 

   Serial.println("SD Card Found"); 

  } 

  else { 

    Serial.println("SD Card Not Found"); 

  } 

//Write Header
  dataFile = SD.open("sensor.csv", FILE_WRITE); 

  dataFile.println("Time,Value"); 

} 



void loop() { 
Serial.println(position); 
//Read Potentiometer Value 
int sensorValue = analogRead(potPin); 
analogRead(A0); 
sensorValue = analogRead(potPin); 

 

Serial.print("Value = "); 

Serial.println(sensorValue); 

 


//Read Current Time 
millis(); 
//Open CSV File 

SD.open("sensor.csv", FILE_WRITE); 
  //Write Time and Value
  dataFile.print("Time");
  dataFile.print(millis()/1000);
  dataFile.print(",");
  dataFile.print("Value"); 
  dataFile.println(sensorValue);

 //Close File 
dataFile.close(); 
//Wait 1 Second
delay(1000);
} 

 



 