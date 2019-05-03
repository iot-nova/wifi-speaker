#include "prototypes.h"

char ssid[] = "Hexus";
char pass[] = "Password123";

//http://www.noiseaddicts.com/samples_1w72b820/1449.mp3

int status = WL_IDLE_STATUS;

ESP8266WebServer server (8080);

//##################################################

void setup()
{
  Serial.begin(115200);
  
  while(!Serial)
  {
    ;
  }

  if(WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");

    while(true);
  }

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    status = WiFi.begin(ssid, pass);

    delay(10000);
  }

  server.on("/", handlerDisplayForm);
  server.on("/play", handlerHandleURLForm);
  
  server.begin();

  printWifiStatus();
}

//##################################################

void loop()
{
  server.handleClient();

  loopSong();
}

//##################################################

void handlerDisplayForm()
{
  server.send(200, "text/html", webServerDisplayForm());
}

//##################################################

void handlerHandleURLForm()
{
  server.send(200, "text/html", webServerHandleURLForm());

  playSong(server.arg("url"));
}

//##################################################

void printWifiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
