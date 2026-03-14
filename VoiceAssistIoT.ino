#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "Audio.h"
#include <UrlEncode.h>
#include <LiquidCrystal.h>
const int rs = 5, en = 4, d4 = 18, d5 = 19, d6 = 13,d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define BOARDNO"001/"
const char* ssid = "iotdata";
const char* password = "12345678";
String Question = "";
#define I2S_DOUT 25
#define I2S_BCLK 27
#define I2S_LRC 26
Audio audio;
void setup()
{
Serial.begin(115200);
Serial2.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.disconnect();
lcd.begin(16,2);
lcd.print("ChatGPT Receiver");
while (!Serial);
lcd.setCursor(0,1);
lcd.print("Connecting...
");
// wait for WiFi connection
WiFi.begin(ssid, password);
Serial.print("Connecting to ");
Serial.println(ssid);
while (WiFi.status() != WL_CONNECTED)
{
delay(1000);
Serial.print(".");
}
Serial.println("connected");
Serial.print("IP address: ");
Serial.println(WiFi.localIP());
audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
audio.setVolume(64);
lcd.setCursor(0,1);
lcd.print("
");
pinMode(33,INPUT);
pinMode(14,OUTPUT);
digitalWrite(14,1);
}
int di;
char lf;
char oc;
String ptt;
int lc,df;
int i;
int aval;
/*********** COMMUNICATIONSELECTION***********/
/* CommentOutTheOneYouAreNotUsing */
HTTPClient http; //Declare object of class HTTPClient
long l;
WiFiClient client;
String inputString = "";
// a String to hold incoming data
boolean stringComplete = false; // whether the string is complete
void loop()
{
// ptt="http://www.iotclouddata.com/24log/069/getstatus1.php";
// http.begin(client,ptt);
//Specify request destination
// http.addHeader("Content-Type", "text/plain"); //Specify content-type
header
// int httpCode = http.POST("A=Test"); //Send the request
// String payload = http.getString();
//Get the response payload
// Serial.println(httpCode); //Print HTTP return code
// Serial.println(payload); //Print request response payload
// ptt="http://www.iotclouddata.com/24log/001/sendChat.php?A=payload";
// http.begin(client,ptt);
//Specify request destination
// http.addHeader("Content-Type", "text/plain"); //Specify content-type
header
// int httpCode1 = http.POST("A=Test"); //Send the request
// String payload1 = http.getString();
//Get the response payload
// Serial.println(httpCode1); //Print HTTP return code
// Serial.println(payload1); //Print request response payload
ptt="http://www.iotclouddata.com/24log/";
ptt=ptt+BOARDNO+"getchat.php";
//Serial.println(ptt);
http.begin(client,ptt);
//Specify request destination
http.addHeader("Content-Type", "text/plain"); //Specify content-type
header
int httpCode2 = http.POST("A=Test"); //Send the request
String payload2 = http.getString();
//Get the response payload
Serial.println(httpCode2); //Print HTTP return code
Serial.println(payload2); //Print request response payload
Serial.print("Press Button : ");
// Question=payload;
JsonDocument doc;
DeserializationError error = deserializeJson(doc, payload2);
JsonObject response = doc["response"];
const char* response_id = response["id"];
/chatcmpl8ufL4Uz56MvJNp5eVTj7SnaoBHia6"
Serial.println(response_id);
const char* response_object = response["object"]; // "chat.completion"
JsonObject response_choices_0 = response["choices"][0];
const char* sensor1 = response_choices_0["message"]["content"]; //
"Hello! ...
//Serial.println(sensor1);
Serial.println(strlen(sensor1));
String s[(strlen(sensor1)/200)+1];
Serial.println((strlen(sensor1)/200)+1);
audio.loop();
for(int y=0;y<((strlen(sensor1)/200)+1);y++)
{
s[y]=String(sensor1).substring((y*200), (y*200)+200);
Serial.print(s[y]);
Serial.println("------------------------------------------");
audio.loop();
}
Serial.println("++++++++++++++++++++++++++++++++++++++++++");
Question=sensor1;
while (digitalRead(33)==1)
{
audio.loop();
}
//Question=payload;
while (digitalRead(33)==0)
{
audio.loop();
}
for(int yy=0;yy<((strlen(sensor1)/200)+1);yy++)
{
Serial.println("------------------------------------------");
Serial2.print("*");
Serial2.print(s[yy]);
if(s[yy]=="Motor on")
{
digitalWrite(32,0);
}
if(s[yy]=="Motor off")
{
digitalWrite(32,1);
}
digitalWrite(14,0);
Serial2.print("#");
Serial.print("Answer : "); Serial.println(s[yy]);
lcd.setCursor(0,0);
lcd.print(s[yy]);
Serial.println("#########################################");
audio.connecttospeech(s[yy].c_str(), "en");
Question = "";
digitalWrite(14,1);
while (digitalRead(33)==1)
{
audio.loop();
}
while (digitalRead(33)==0)
{
audio.loop();
}
}
}
void audio_info(const char *info) {
Serial.print("audio_info: "); Serial.println(info);
}
