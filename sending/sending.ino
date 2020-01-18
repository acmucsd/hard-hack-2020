#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "fir-esp-41099.firebaseio.com"
#define FIREBASE_AUTH "xbbCax7dKSjH7WwBFNiU7JtWz7rR8r66XlPbYcsf"

#define WIFI_SSID "NoFreeHotspot4U"
#define WIFI_PASSWORD "ONE WORD ALL LOWERCASE"

void setup() {
  //Begin serial output
  Serial.begin(9600);

  //Attempt to connect to wifi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  //If we get here, we are connected!
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  //start firebase client
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  //Will repeatedly change the value of "test" field from 3.14 to 6.28 and back
  Firebase.setFloat("test", 3.14);
  delay(1000);
  Firebase.setFloat("test", 6.28);
  delay(1000);

  Firebase.set("nested/test", "hello");
  delay(1000);
  Firebase.set("nested/test", "world");
  delay(1000);
  
}