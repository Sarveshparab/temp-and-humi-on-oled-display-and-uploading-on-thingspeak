#include <Wire.h>
#include <WiFi.h> 
#include "SSD1306.h"
#include <DHT.h>

 
String apiKey = "UMLGF3DLRK9IFXZ2";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "Sarvesh";     // replace with your wifi ssid and wpa2 key
const char *pass =  "8879607830";
const char* server = "api.thingspeak.com";


#define dataPin1 16
#define dataPin2 16
#define dataPin3 16
#define dataPin4 16
    
#define DHTTYPE1 DHT11
#define DHTTYPE2 DHT11
#define DHTTYPE3 DHT11 
#define DHTTYPE4 DHT11      

SSD1306  display(0x3C, 15, 2);   // D3 -> SDA,D4 -> SCL
DHT dht1(dataPin1, DHTTYPE1);
DHT dht2(dataPin2, DHTTYPE2);
DHT dht3(dataPin3, DHTTYPE3);
DHT dht4(dataPin4, DHTTYPE4);

WiFiClient client;
void setup(){
  Serial.begin(115200); // or 9600 tak 
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  dht1.begin(); // initialize dht
  dht2.begin();
  dht3.begin();
  dht4.begin();
  Serial.println("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
        delay(500);
        Serial.print(".");
  }
   Serial.println("");
    Serial.println("WiFi connected");  

}
void displayWeather1 ()
{ display.clear();
  float h = dht1.readHumidity();
  // Read temperature as Celsius
  float t = dht1.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht1.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 1 Failed!");
    return;
  }
 
  display.clear();

  display.drawString(30, 0, "DTH 1 ");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F");
  
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(t);
                             postStr +="&field2=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
  
  
}

void displayWeather2(){ //Creating a function to read and display temperature and humidity on OLED display
  float h = dht2.readHumidity();
  // Read temperature as Celsius
  float t = dht2.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht2.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 2 Failed!");
    return;
  }
 

  display.clear();

  display.drawString(30, 0, "DTH 2");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F"); 
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field3=";
                             postStr += String(t);
                             postStr +="&field4=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
  
  
}

void displayWeather3 ()
{ display.clear();
  float h = dht3.readHumidity();
  // Read temperature as Celsius
  float t = dht3.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht3.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 3 Failed!");
    return;
  }

 
  display.clear();

  display.drawString(30, 0, "DTH 3 ");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F"); 
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field5=";
                             postStr += String(t);
                             postStr +="&field6=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
  
  
}

void displayWeather4 ()
{ display.clear();
  float h = dht4.readHumidity();
  // Read temperature as Celsius
  float t = dht4.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht4.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 4 Failed!");
    return;
  }
  
  display.clear();

  display.drawString(30, 0, "DTH 4 ");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F"); 
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field7=";
                             postStr += String(t);
                             postStr +="&field8=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
  
    
}
void loop(){

  displayWeather1(); //Calling back the displayWeather function
  display.display();
  delay (5000);
  displayWeather2();
  display.display();
  delay (5000);
  displayWeather3();
  display.display();
  delay (5000);
  displayWeather4();
  display.display();
  delay (5000);
}
