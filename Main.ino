#include "prototypes.h"

char ssid[] = "Hexus";
char pass[] = "Password123";

AudioGeneratorMP3 *mp3;
AudioFileSourceHTTPStream *file;
AudioFileSourceBuffer *buff;
AudioOutputI2S *out;

int status = WL_IDLE_STATUS;

ESP8266WebServer server (8080);

//const char* URL = "http://www.noiseaddicts.com/samples_1w72b820/4353.mp3";

//##################################################

void setup()
{
  Serial.begin(115200);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    status = WiFi.begin(ssid, pass);

    delay(10000);
  }

  server.on("/", webServerDisplayForm);
  server.on("/play", webServerHandleURLForm);
  
  server.begin();

  printWifiStatus();

  /*
  file = new AudioFileSourceHTTPStream(URL);
  buff = new AudioFileSourceBuffer(file, 2048);
  out = new AudioOutputI2S();
  mp3 = new AudioGeneratorMP3();

  mp3->begin(buff, out);
  */
}

//##################################################

void loop()
{  
  server.handleClient();

  if(mp3)
  {
    if(mp3->isRunning())
    {
      if(!mp3->loop()) mp3->stop();
    }
    
    else
    {
      Serial.println("MP3 done !");
      mp3 = NULL;
    }
  }
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
