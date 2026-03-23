#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define MQ135_PIN 34

const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

float temperature;
float humidity;
int gasValue;

void handleRoot() {
  Serial.println("Client connected to webpage!");

  String html = "<html><head>";
  html += "<meta http-equiv='refresh' content='3'/>";
  html += "<title>Air Quality Monitor</title></head><body>";
  html += "<h1>ESP32 Air Quality Monitor</h1>";
  html += "<p>Temperature: " + String(temperature) + " C</p>";
  html += "<p>Humidity: "    + String(humidity)    + " %</p>";
  html += "<p>Gas Value: "   + String(gasValue)    + "</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting ESP32...");

  dht.begin();

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  temperature = dht.readTemperature();
  humidity    = dht.readHumidity();
  gasValue    = analogRead(MQ135_PIN);

  Serial.println("------ SENSOR READINGS ------");
  Serial.print("Temperature: "); Serial.println(temperature);
  Serial.print("Humidity: ");    Serial.println(humidity);
  Serial.print("Gas Value: ");   Serial.println(gasValue);
  Serial.print("IP: ");          Serial.println(WiFi.localIP());
  Serial.println("-----------------------------\n");

  server.handleClient();
  delay(2000);
}
