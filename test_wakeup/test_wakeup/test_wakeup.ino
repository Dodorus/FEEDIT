#include <ESP8266WiFi.h>

const char* ssid = "HUAWEI_DOM";           // WiFi SSID
const char* password = "00069597";    // WiFi password
//#define NB_TRYWIFI     10             // nbr d'essai connexion WiFi, number of try to connect WiFi


const int sleepSeconds = 3;



void setup() {
  Serial.begin(74880);
  Serial.println("\n\nWake up");

  // Connect D0 to RST to wake up
  pinMode(D0, WAKEUP_PULLUP);

  Serial.println("Initialize DHT sensor");
  //dht.begin();

  Serial.println("Read DHT sensor");
  //float humidity = dht.readHumidity();
  //float temperature = dht.readTemperature();
  //if (isnan(humidity) || isnan(temperature)) {
  //  Serial.println("Failed to read from DHT sensor!");
  //}
  //float heatIndex = dht.computeHeatIndex(temperature, humidity, false);


  //Serial.printf("Humidity:    %s %%\nTemperature: %s *C\nHeat index:  %s *C\n", str_humidity, str_temperature, str_heatIndex);

  //Serial.printf("Sleep for %d seconds\n\n", sleepSeconds);


  // convert to microseconds
  ESP.deepSleep(sleepSeconds * 1000000);
}


void loop() {

}
