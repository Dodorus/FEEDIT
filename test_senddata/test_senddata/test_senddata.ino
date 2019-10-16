#include <ESP8266WiFi.h>
const char* ssid     = "HUAWEI_DOM";      // SSID
const char* password = "00069597";      // Password
const char* host = "kunzserver.synology.me";  // IP ServeP
const int   port = 80;            // Port
const int   watchdog = 5000;        // Schreibefruenz
unsigned long previousMillis = millis(); 
 
void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  delay(5000);  
    unsigned long currentMillis = millis();
 
  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;
    WiFiClient client;
 
    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      return;
    }
 
    String url = "/_werte.php?wert=";
    url += String(millis());
 
    // Envoi la requete au serveur - This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
      while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  }
}
