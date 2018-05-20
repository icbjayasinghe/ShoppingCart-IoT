#include <stdio.h>
#include <string.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>


char id[100];
char data[5];
int val =0;


void setup() {
  Serial.begin(9600);

//  Serial.write(byte(0xFF)); //header
//  Serial.write(byte(0x01)); //reserved
//  Serial.write(byte(0x09)); //length
//  Serial.write(byte(0x87)); //command : automode
//  Serial.write(byte(0x01)); //data 1
//  Serial.write(byte(0x03)); //data 2
//  Serial.write(byte(0x02)); //data 3
//  Serial.write(byte(0x00)); //data 4
//  Serial.write(byte(0x10)); //data 5
//  Serial.write(byte(0x20)); //data 6
//  Serial.write(byte(0x30)); //data 7
//  Serial.write(byte(0x40)); //data 8
//  Serial.write(byte(0x37)); //checksum

  delay(500);
  
  Serial.flush();
  Serial.println();
  Serial.println("Waiting for RFID tag.... ");

}

void loop() {

  val = Serial.read();
  while(! Serial.available()){
    Serial.print("..");
    val = Serial.read(); 
    delay(1000);    
    }
//    Serial.write(Serial.read());
  //Serial.print(data[1], HEX);
  Serial.read();
  Serial.read();
  Serial.read();
  Serial.read();
  data[0] = Serial.read();
  data[1] = Serial.read();
  data[2] = Serial.read();
  data[3] = Serial.read();
  data[4] = Serial.read();
  data[5]=Serial.read();
  Serial.read();
  Serial.read();
  Serial.read();
  for(int i=0; i<5; i++){
    //if(data[i] < 16) Serial.print("0");
    //Serial.print(data[i]);
    //Serial.println(HEX(data[i]));
    //Serial.print("hari");
    }
  memcpy(id, data, 7);
  id[7] = '\0'; 
  //Serial.println('____');  
  Serial.println(id);
  //Serial.println('____');
  delay(3000);
}
