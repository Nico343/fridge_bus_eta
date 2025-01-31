#include <Arduino.h>
#include <WiFi.h>
#include <HTTPclient.h>
#include <ArduinoJson.h>
// put function declarations here:
// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <GFX.h>

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_4C.h>
#include <GxEPD2_7C.h>
#include <Fonts/Org_01.h>

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

int b1[2] = {2, 17}, b2[2] = {8, 17}, b3[2] = {1, 33}, b4[2] = {5, 21}, d = 1000;

const char* ssid = "39 Nam Cheong St (2)";
const char* password = "2MULAN&mushu";

void helloWorld();
void Refresh();

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  delay(5000);

  display.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
  Refresh();
  display.hibernate();
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    // Serial.println("Hi!");
    HTTPClient client;

    client.begin(""+ String());
    int httpCode = client.GET();
  }
  else{
    // Serial.println("Bye!");
    Serial.println("connection lost");
  }
  delay(d);

  // getData();
  // Refresh();
  // display.hibernate();
  // sleep(60);
};

void Refresh(){
  display.setRotation(1);
  display.setFont(&Org_01);
  display.setTextColor(GxEPD_BLACK);
  display.setFullWindow();

  do{
  display.fillScreen(GxEPD_WHITE);

  display.fillRect(0, 0, 250, 30, GxEPD_BLACK);
  display.fillRect(0, 62, 250, 30, GxEPD_BLACK);
  display.setTextColor(GxEPD_WHITE);
  display.setFont(&Org_01);
  display.setTextSize(4);

  display.setCursor(3, 21);
  display.print("18");
  display.setCursor(3, 83);
  display.print("45");

  display.setCursor(116, 21);
  display.print(b1[0]);
  display.setCursor(180, 21);
  display.print(b1[1]);
  display.setCursor(116, 83);
  display.print(b2[0]);
  display.setCursor(180, 83);
  display.print(b2[1]);

  display.setTextSize(1);
  display.setCursor(227, 86);
  display.print("MIN");
  display.setCursor(138, 86);
  display.print("MIN");
  display.setCursor(227, 24);
  display.print("MIN");
  display.setCursor(138, 24);
  display.print("MIN");

  display.setTextColor(GxEPD_BLACK);

  display.setTextSize(4);
  display.setCursor(3, 53);
  display.print("2E");
  display.setCursor(3, 115);
  display.print("475X");
  display.setCursor(116, 53);
  display.print(b3[0]);
  display.setCursor(180, 53);
  display.print(b3[1]);
  display.setCursor(116, 115);
  display.print(b4[0]);
  display.setCursor(180, 115);
  display.print(b4[1]);

  display.setTextSize(1);
  display.setCursor(138, 56);
  display.print("MIN");
  display.setCursor(227, 56);
  display.print("MIN");
  display.setCursor(138, 118);
  display.print("MIN");
  display.setCursor(227, 118);
  display.print("MIN");
  } while(display.nextPage());
}
