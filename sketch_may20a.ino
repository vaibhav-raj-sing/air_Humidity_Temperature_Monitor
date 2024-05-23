#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include<OakOLED.h>
#include<MQ135.h>
#include<DHT.h>
#define DHTPIN D4 // Selecting the pin at which we have connected DHT11
#define DHTTYPE DHT11
DHT dht( DHTPIN,DHTTYPE);
OakOLED oled;
//String apiKey ="7W20SY41EPFL8JNA"; // T&H(1-4)
//String apiKey ="VW58O28LQVJX8IKX"; // T&H(4-8)
//String apiKey ="3XU7QX2GNQ0FLGR2"; // T&H(8-12)
String apiKey ="ICNE1CK3YU9FVQ2K"; // T&H(12-16)
//String apiKey="8TKQNP99GI16SSVG"; //T&H(16-20)
//String apiKey="276Y3334RNDG3N2B";//T&H(20-24)
//String apiKey="SB0VONCIBMEXR5B8";//T&H(24-28)
const char* server = "api.thingspeak.com";
// WiFi parameters to be configured
const char* ssid ="uniconvergetech2_4g"; // Write here your router's username
const char* password ="#uct@12345"; // Write here your router's password
WiFiClient client;
void setup(void)
{
Serial.begin(9600);
// Connect to WiFi
WiFi.begin(ssid, password);
oled.begin();
oled.clearDisplay();
oled.setTextSize(1);
oled.setTextColor(1);
oled.setCursor(0,0);
oled.println("CONNECTING TO WiFi");
oled.display();
// while wifi not connected yet, print '.'
// then after it connected, get out of the loop
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
//print a new line, then print WiFi connected and the IP address
Serial.println("");
oled.clearDisplay();
oled.setTextSize(1);
oled.setTextColor(1);
oled.setCursor(0,0);
oled.println("CONNECTED TO WiFi");
oled.display();
Serial.println("WiFi connected");
// Print the IP address
Serial.println(WiFi.localIP());
delay(1000);
dht.begin ( );
}
void loop() {
// Nothing
MQ135 gasSensor = MQ135(A0);
float air_quality = gasSensor.getPPM();
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t))
{
Serial.println("Failed to read from DHT sensor!");
return;
}
if (client.connect(server,80)) // "184.106.153.149" or api.thingspeak.com
{
String postStr = apiKey;
postStr +="&field1=";
postStr += String(t);
postStr +="&field2=";
postStr += String(h);
postStr +="&field3=";
postStr += String(air_quality);
postStr += "\r\n\r\n\r\n";
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);
Serial.print("Temperature: ");
Serial.print(t);
Serial.print(" degrees Celcius, Humidity: ");
Serial.print(h);
Serial.println("%, Air_Quality");
Serial.println(air_quality);
Serial.println("PPM. Send to Thingspeak.");
}
client.stop();
oled.clearDisplay();
oled.setTextSize(1.5);
oled.setTextColor(1);
oled.setCursor(0,0);
oled.print("Temp: ");
oled.println(t);
oled.print("Humid: ");
oled.println(h);
oled.print("AQI: ");
oled.println(air_quality);
oled.display();
Serial.println("Waiting...");
delay(10000);
}
