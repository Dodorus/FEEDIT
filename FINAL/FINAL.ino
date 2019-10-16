#include <ESP8266WiFi.h>
#include <HX711_ADC.h>
#include <EEPROM.h>

const char* ssid = "HUAWEI_DOM";    // WiFi SSID klf-45318_EXT
const char* password = "00069597";    // WiFi passwort
#define durationSleep  10             // secondes
#define NB_TRYWIFI     10             // versuche of try to connect WiFi

//HX711 constructor (dout pin, sck pin):
HX711_ADC LoadCell(D1, D5);
const int eepromAdress = 0;
long t;
  
void setup() {
  Serial.begin(9600); delay(1000);
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.println("Starting...");
  
  int _try = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("..");
    delay(5000);
    _try++;
    if ( _try >= NB_TRYWIFI ) {
        Serial.println("Impossible to connect WiFi network, go to deep sleep");
        ESP.deepSleep(durationSleep * 1000000);
    }
  }
  Serial.println("Connected to the WiFi network");
  Serial.print ( "IP address: " );
  Serial.println ( WiFi.localIP() );

  calValue = 400.0; // Calib Wert 
  Serial.println();
  Serial.println("Messbegin");
  LoadCell.begin();
  
  long stabilisingtime = 2000; // tare preciscion can be improved by adding a few seconds of stabilising time
  LoadCell.start(stabilisingtime);
  
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Kommt immer else vor, Domi weiss nicht warum");
  }
  else {
    LoadCell.setCalFactor(calValue); // user set calibration value (float)
    Serial.println("Startup + tare is complete");
  }

  if (millis() > t + 250) {
   LoadCell.update(); delay(2000);
   float i = LoadCell.getData();
   Serial.print("Load_cell output val: ");
   Serial.println(i);
   t = millis();
  }
  
  ESP.deepSleep(durationSleep * 1000000);
}

void loop() {
}
