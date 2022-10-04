#include <WiFi.h>
#include <WebServer.h>
 
const char* ssid = "ESP";  // Enter SSID here
const char* password = "20302030";  //Enter Password here
 
WebServer server(80);
 
uint8_t LED1Gpin = 23;
bool LED1G_status = LOW;
 
uint8_t LED1Opin = 18;
bool LED1O_status = LOW;
 
uint8_t LED1Rpin = 4;
bool LED1R_status = LOW;

uint8_t LED2Gpin = 22;
bool LED2G_status = LOW;
 
uint8_t LED2Opin = 5;
bool LED2O_status = LOW;
 
uint8_t LED2Rpin = 0;
bool LED2R_status = LOW;

uint8_t LED3Gpin = 21;
bool LED3G_status = LOW;
 
uint8_t LED3Opin = 17;
bool LED3O_status = LOW;
 
uint8_t LED3Rpin = 2;
bool LED3R_status = LOW;

uint8_t LED4Gpin = 19;
bool LED4G_status = LOW;
 
uint8_t LED4Opin = 16;
bool LED4O_status = LOW;
 
uint8_t LED4Rpin = 15;
bool LED4R_status = LOW;
 
void setup() {
  
  Serial.begin(115200);
  pinMode(LED1Gpin, OUTPUT);
  pinMode(LED1Opin, OUTPUT);
  pinMode(LED1Rpin, OUTPUT);
  
  pinMode(LED2Gpin, OUTPUT);
  pinMode(LED2Opin, OUTPUT);
  pinMode(LED2Rpin, OUTPUT);
 
  pinMode(LED3Gpin, OUTPUT);
  pinMode(LED3Opin, OUTPUT);
  pinMode(LED3Rpin, OUTPUT);
    
  pinMode(LED4Gpin, OUTPUT);
  pinMode(LED4Opin, OUTPUT);
  pinMode(LED4Rpin, OUTPUT);
 
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  delay(100);
   
  server.on("/", handle_OnConnect);
  
  server.on("/led1Gon", handle_led1Gon);
  server.on("/led1Goff", handle_led1Goff);
  server.on("/led1Oon", handle_led1Oon);
  server.on("/led1Ooff", handle_led1Ooff);
  server.on("/led1Ron", handle_led1Ron);
  server.on("/led1Roff", handle_led1Roff);

  server.on("/led2Gon", handle_led2Gon);
  server.on("/led2Goff", handle_led2Goff);
  server.on("/led2Oon", handle_led2Oon);
  server.on("/led2Ooff", handle_led2Ooff);
  server.on("/led2Ron", handle_led2Ron);
  server.on("/led2Roff", handle_led2Roff);

  server.on("/led3Gon", handle_led3Gon);
  server.on("/led3Goff", handle_led3Goff);
  server.on("/led3Oon", handle_led3Oon);
  server.on("/led3Ooff", handle_led3Ooff);
  server.on("/led3Ron", handle_led3Ron);
  server.on("/led3Roff", handle_led3Roff);

  server.on("/led4Gon", handle_led4Gon);
  server.on("/led4Goff", handle_led4Goff);
  server.on("/led4Oon", handle_led4Oon);
  server.on("/led4Ooff", handle_led4Ooff);
  server.on("/led4Ron", handle_led4Ron);
  server.on("/led4Roff", handle_led4Roff);
  
  server.onNotFound(handle_NotFound);
   
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  
  if(LED1G_status)
  {digitalWrite(LED1Gpin, HIGH);}
  else
  {digitalWrite(LED1Gpin, LOW);}
  if(LED1O_status)
  {digitalWrite(LED1Opin, HIGH);}
  else
  {digitalWrite(LED1Opin, LOW);}
  if(LED1R_status)
  {digitalWrite(LED1Rpin, HIGH);}
  else
  {digitalWrite(LED1Rpin, LOW);}
  
  if(LED2G_status)
  {digitalWrite(LED2Gpin, HIGH);}
  else
  {digitalWrite(LED2Gpin, LOW);}
  if(LED2O_status)
  {digitalWrite(LED2Opin, HIGH);}
  else
  {digitalWrite(LED2Opin, LOW);}
  if(LED2R_status)
  {digitalWrite(LED2Rpin, HIGH);}
  else
  {digitalWrite(LED2Rpin, LOW);}

  if(LED3G_status)
  {digitalWrite(LED3Gpin, HIGH);}
  else
  {digitalWrite(LED3Gpin, LOW);}
  if(LED3O_status)
  {digitalWrite(LED3Opin, HIGH);}
  else
  {digitalWrite(LED3Opin, LOW);}
  if(LED3R_status)
  {digitalWrite(LED3Rpin, HIGH);}
  else
  {digitalWrite(LED3Rpin, LOW);}

  if(LED4G_status)
  {digitalWrite(LED4Gpin, HIGH);}
  else
  {digitalWrite(LED4Gpin, LOW);}
  if(LED4O_status)
  {digitalWrite(LED4Opin, HIGH);}
  else
  {digitalWrite(LED4Opin, LOW);}
  if(LED4R_status)
  {digitalWrite(LED4Rpin, HIGH);}
  else
  {digitalWrite(LED4Rpin, LOW);}
}
 
void handle_OnConnect() {
  
  LED1G_status = LOW;
  LED1O_status = LOW;
  LED1R_status = LOW;

  LED2G_status = LOW;
  LED2O_status = LOW;
  LED2R_status = LOW;

  LED3G_status = LOW;
  LED3O_status = LOW;
  LED3R_status = LOW;

  LED4G_status = LOW;
  LED4O_status = LOW;
  LED4R_status = LOW;

  Serial.println("G1 : OFF | O1 Status: OFF | R1 Status: OFF | G2 : OFF | O2 Status: OFF | R2 Status: OFF | G3 : OFF | O3 Status: OFF | R3 Status: OFF | G4 : OFF | O4 Status: OFF | R4 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
//______________________________________________//
void handle_led1Gon() {
  LED1G_status = HIGH;
  Serial.println("G1 Status: ON");
  server.send(200, "text/html", SendHTML(true,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led1Goff() {
  LED1G_status = LOW;
  Serial.println("G1 Status: OFF");
  server.send(200, "text/html", SendHTML(false,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led1Oon() {
  LED1O_status = HIGH;
  Serial.println("O1 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,true,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led1Ooff() {
  LED1O_status = LOW;
  Serial.println("O1 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,false,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led1Ron() {
  LED1R_status = HIGH;
  Serial.println("R1 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,true,LED2G_status,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led1Roff() {
  LED1R_status = LOW;
  Serial.println("R1 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,false,LED2G_status,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
//______________________________________________//
//______________________________________________//
//______________________________________________//
void handle_led2Gon() {
  LED2G_status = HIGH;
  Serial.println("G2 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,true,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led2Goff() {
  LED2G_status = LOW;
  Serial.println("G2 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,false,LED2O_status,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led2Oon() {
  LED2O_status = HIGH;
  Serial.println("O2 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,true,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led2Ooff() {
  LED2O_status = LOW;
  Serial.println("O2 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,false,LED2R_status,LED3R_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led2Ron() {
  LED2R_status = HIGH;
  Serial.println("R2 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,true,LED3R_status,LED3O_status,LED3G_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led2Roff() {
  LED2R_status = LOW;
  Serial.println("R2 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,false,LED3R_status,LED3O_status,LED3G_status,LED4G_status,LED4O_status,LED4R_status)); 
}
//______________________________________________//
//______________________________________________//
//______________________________________________//
void handle_led3Gon() {
  LED3G_status = HIGH;
  Serial.println("G3 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,true,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led3Goff() {
  LED3G_status = LOW;
  Serial.println("G3 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,false,LED3O_status,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led3Oon() {
  LED3O_status = HIGH;
  Serial.println("O3 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,true,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led3Ooff() {
  LED3O_status = LOW;
  Serial.println("O3 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,false,LED3R_status,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led3Ron() {
  LED3R_status = HIGH;
  Serial.println("R3 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,true,LED4G_status,LED4O_status,LED4R_status)); 
}
void handle_led3Roff() {
  LED3R_status = LOW;
  Serial.println("R3 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,false,LED4G_status,LED4O_status,LED4R_status)); 
}
//______________________________________________//
//______________________________________________//
//______________________________________________//
void handle_led4Gon() {
  LED4G_status = HIGH;
  Serial.println("G4 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,LED3R_status,true,LED4O_status,LED4R_status)); 
}
void handle_led4Goff() {
  LED4G_status = LOW;
  Serial.println("G4 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,LED3R_status,false,LED4O_status,LED4R_status)); 
}
void handle_led4Oon() {
  LED4O_status = HIGH;
  Serial.println("O4 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,LED3R_status,LED4G_status,true,LED4R_status)); 
}
void handle_led4Ooff() {
  LED4O_status = LOW;
  Serial.println("O4 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,LED3R_status,LED4G_status,false,LED4R_status)); 
}
void handle_led4Ron() {
  LED4R_status = HIGH;
  Serial.println("R4 Status: ON");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,true)); 
}
void handle_led4Roff() {
  LED4R_status = LOW;
  Serial.println("R4 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1G_status,LED1O_status,LED1R_status,LED2G_status,LED2O_status,LED2R_status,LED3G_status,LED3O_status,LED3R_status,LED4G_status,LED4O_status,false)); 
}
//______________________________________________//
void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
 
String SendHTML(uint8_t led1Gstat,uint8_t led1Ostat, uint8_t led1Rstat,uint8_t led2Gstat,uint8_t led2Ostat, uint8_t led2Rstat,uint8_t led3Gstat,uint8_t led3Ostat, uint8_t led3Rstat,uint8_t led4Gstat,uint8_t led4Ostat, uint8_t led4Rstat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>Control Room</h1>\n";
  ptr +="<h3>Traffic Light System</h3>\n";
   
   if(led1Gstat)
  {ptr +="<p>Green LED Status: ON</p><a class=\"button button-off\" href=\"/led1Goff\">OFF</a>\n";}
  else
  {ptr +="<p>Orange LED Status: OFF</p><a class=\"button button-on\" href=\"/led1Gon\">ON</a>\n";}
  if(led1Ostat)
  {ptr +="<p>Orange LED Status: ON</p><a class=\"button button-off\" href=\"/led1Ooff\">OFF</a>\n";}
  else
  {ptr +="<p>Orange LED Status: OFF</p><a class=\"button button-on\" href=\"/led1Oon\">ON</a>\n";}
  if(led1Rstat)
  {ptr +="<p>Red LED Status: ON</p><a class=\"button button-off\" href=\"/led1Roff\">OFF</a>\n";}
  else
  {ptr +="<p>Red LED Status: OFF</p><a class=\"button button-on\" href=\"/led1Ron\">ON</a>\n";}

  if(led2Gstat)
  {ptr +="<p>Green LED Status: ON</p><a class=\"button button-off\" href=\"/led2Goff\">OFF</a>\n";}
  else
  {ptr +="<p>Green LED Status: OFF</p><a class=\"button button-on\" href=\"/led2Gon\">ON</a>\n";}
  if(led2Ostat)
  {ptr +="<p>Orange LED Status: ON</p><a class=\"button button-off\" href=\"/led2Ooff\">OFF</a>\n";}
  else
  {ptr +="<p>Orange LED Status: OFF</p><a class=\"button button-on\" href=\"/led2Oon\">ON</a>\n";}
  if(led2Rstat)
  {ptr +="<p>Red LED Status: ON</p><a class=\"button button-off\" href=\"/led2Roff\">OFF</a>\n";}
  else
  {ptr +="<p>Red LED Status: OFF</p><a class=\"button button-on\" href=\"/led2Ron\">ON</a>\n";}

  if(led3Gstat)
  {ptr +="<p>Green LED Status: ON</p><a class=\"button button-off\" href=\"/led3Goff\">OFF</a>\n";}
  else
  {ptr +="<p>Green LED Status: OFF</p><a class=\"button button-on\" href=\"/led3Gon\">ON</a>\n";}
  if(led3Ostat)
  {ptr +="<p>Orange LED Status: ON</p><a class=\"button button-off\" href=\"/led3Ooff\">OFF</a>\n";}
  else
  {ptr +="<p>Orange LED Status: OFF</p><a class=\"button button-on\" href=\"/led3Oon\">ON</a>\n";}
  if(led3Rstat)
  {ptr +="<p>Red LED Status: ON</p><a class=\"button button-off\" href=\"/led3Roff\">OFF</a>\n";}
  else
  {ptr +="<p>Red LED Status: OFF</p><a class=\"button button-on\" href=\"/led3Ron\">ON</a>\n";}

  if(led4Gstat)
  {ptr +="<p>Green LED Status: ON</p><a class=\"button button-off\" href=\"/led4Goff\">OFF</a>\n";}
  else
  {ptr +="<p>Green LED Status: OFF</p><a class=\"button button-on\" href=\"/led4Gon\">ON</a>\n";}
  if(led4Ostat)
  {ptr +="<p>Orange LED Status: ON</p><a class=\"button button-off\" href=\"/led4Ooff\">OFF</a>\n";}
  else
  {ptr +="<p>Orange LED Status: OFF</p><a class=\"button button-on\" href=\"/led4Oon\">ON</a>\n";}
  if(led4Rstat)
  {ptr +="<p>Red LED Status: ON</p><a class=\"button button-off\" href=\"/led4Roff\">OFF</a>\n";}
  else
  {ptr +="<p>Red LED Status: OFF</p><a class=\"button button-on\" href=\"/led4Ron\">ON</a>\n";}

 
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
