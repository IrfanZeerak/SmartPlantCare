#include <DHT.h>

#define DHTPIN 2      // Pin where the humidity sensor is connected
#define DHTTYPE DHT11  // DHT11 or DHT22, depending on your sensor

int motorPin = 3;  // Pin to control the water motor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
   // Delay to stabilize sensor readings

  float humidity = dht.readHumidity();

  // Check if there is Bluetooth data available
  while (Serial.available() > 0) {
    char command = Serial.read();

    // If the received command is '1', turn on the water motor
    if (command == '1') {
      digitalWrite(motorPin, HIGH);  // Turn on the water motor
    } 
    // If the received command is '0', turn off the water motor
    else if (command == '0') {
      digitalWrite(motorPin, LOW);   // Turn off the water motor
    }
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
}