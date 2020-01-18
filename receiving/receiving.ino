#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "insert-auth-here"

#define WIFI_SSID "example-ssid"
#define WIFI_PASSWORD "hunter2"

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
  //Get the value of "test" field
  Serial.print("test: ");
  Serial.println(Firebase.getFloat("test"));

  //Check for errors
  if (Firebase.failed()) {
    Serial.println("Error reading from database");
    Serial.println(Firebase.error());
    return;
  }
}
