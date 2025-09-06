#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

// ---- WiFi Credentials ----
const char* ssid = "your wifi name";// only use 2.4ghz wifi       
const char* password = "your wifi password"; 

// ---- SinricPro Credentials ----
const char* APP_KEY    = "########-7713-1865-86ef-cc310336cb07";  // your app key and other credentials
const char* APP_SECRET = "########-13e7-401b-b568-a8909e714a27-5a94ae85-62d9-4479-a4b0-1f33e9939d94";     
const char* deviceID_light = "684876####4d827f96874564"; 
const char* deviceID_fan   = "684876#####990a558a56483";     

#define LIGHT_RELAY_PIN D1  
#define FAN_RELAY_PIN   D2  

bool onPowerState(const String &deviceId, bool &state) {
  if (deviceId == deviceID_light) {
    digitalWrite(LIGHT_RELAY_PIN, state);
    Serial.println(String("Light is ") + (state ? "ON" : "OFF"));
  }
  if (deviceId == deviceID_fan) {
    digitalWrite(FAN_RELAY_PIN, state);
    Serial.println(String("Fan is ") + (state ? "ON" : "OFF"));
  }
  return true;
}

void setupWiFi() {
  Serial.printf("Connecting to %s", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, HIGH); // LED OFF while not connected (inverted logic)
  }
  Serial.printf("\nWiFi connected! IP: %s\n", WiFi.localIP().toString().c_str());
  digitalWrite(LED_BUILTIN, LOW); // LED ON when connected
}

void setup() {
  Serial.begin(115200);

  pinMode(LIGHT_RELAY_PIN, OUTPUT);
  pinMode(FAN_RELAY_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT); // NodeMCU built-in LED

  digitalWrite(LIGHT_RELAY_PIN, LOW);
  digitalWrite(FAN_RELAY_PIN, LOW);
  digitalWrite(LED_BUILTIN, HIGH); // Start with LED OFF

  setupWiFi();

  SinricProSwitch &mySwitch1 = SinricPro[deviceID_light];
  mySwitch1.onPowerState(onPowerState);

  SinricProSwitch &mySwitch2 = SinricPro[deviceID_fan];
  mySwitch2.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

void loop() {
  SinricPro.handle();

  // Monitor WiFi and update LED
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW); // ON
  } else {
    digitalWrite(LED_BUILTIN, HIGH); // OFF
  }
}
