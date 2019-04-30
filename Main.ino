#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

char ssid[] = "Hexus";
char pass[] = "Password123";

int status = WL_IDLE_STATUS;

ESP8266WebServer server(8080);

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

  server.on("/", loadForm);
  server.on("/play", playMusic);
  
  server.begin();

  printWifiStatus();
}

void loop()
{
  server.handleClient();
}

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

void loadForm()
{
  String result = "<!DOCTYPE HTML>\r\n<html>\r";

  result += "\r<head>";
  result += "\r<title>Music Player</title>";
  result += "\r<link rel=\"icon\" href=\"https://coubsecure-s.akamaihd.net/get/b9/p/coub/simple/cw_timeline_pic/ca60ccae9f6/d6f1484d9b41f5349ba24/med_1411423425_1400401344_image.jpg\" />";
  result += "\r</head>";
  result += "\r<html>";
  result += "\r<body style=\"margin:0; min-height:100vh; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;\">";
  result += "\r<div style=\"background-color:#29232A; min-height:100vh; display:flex; flex-direction:column; justify-content:center;\">";
  result += "\r<div style=\"display:flex; flex-direction:row; justify-content:center;\">";
  result += "\r<form action=\"/play\" style=\"padding:20px; width:calc(100% - 40px); margin:20px; max-width:400px; background-color:#FFFFFF; border-radius:2px;\">";
  result += "\r<div style=\"font-size:0.9em; margin-bottom:5px;\">Enter the URL to the music you want to play:</div>";
  result += "\r<input name=\"url\" style=\"width:100%; font-size:0.9em; box-sizing:border-box; border:1px solid rgba(0,0,0,0.25); border-radius:4px; padding:5px;\" placeholder=\"Enter an url\" type=\"text\" required />";
  result += "\r<div style=\"display:flex; flex-direction:row; justify-content:flex-end;\">";
  result += "\r<button type=\"submit\" style=\"margin-top:20px; border:1px solid #428BCA; border-radius:4px; padding:5px 15px 5px 15px; font-size:0.9em; color:#428BCA; background-color:#FFFFFF; cursor:pointer;\">Play the music</button>";
  result += "\r</div>";
  result += "\r</form>";
  result += "\r</div>";
  result += "\r</div>";
  result += "\r</body>";
  result += "\r</html>";
  
  server.send(200, "text/html", result);
}

void playMusic()
{
  String result = "<!DOCTYPE HTML>\r\n<html>\r";

  result += "\r<head>";
  result += "\r<title>Music Player</title>";
  result += "\r<link rel=\"icon\" href=\"https://coubsecure-s.akamaihd.net/get/b9/p/coub/simple/cw_timeline_pic/ca60ccae9f6/d6f1484d9b41f5349ba24/med_1411423425_1400401344_image.jpg\" />";
  result += "\r</head>";
  result += "\r<body style=\"margin:0; min-height:100vh; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;\">";
  result += "\r<div style=\"background-color:#29232A; min-height:100vh; display:flex; flex-direction:column; justify-content:center;\">";
  result += "\r<div style=\"display:flex; flex-direction:row; justify-content:center;\">";
  result += "\r<div style=\"padding:20px; width:calc(100% - 40px); margin:20px; max-width:400px; background-color:#FFFFFF; border-radius:2px;\">";
  result += "\r<div style=\"font-size:0.9em; margin-bottom:5px;\">Playing song from:</div>";
  result += "\r<div style=\"border:1px solid rgba(0,0,0,0.25); border-radius:4px; padding:5px; line-height:16px; font-size:0.9em; width:100%; box-sizing:border-box; color:rgba(0,0,0,0.75);\">" + server.arg("url") + "</div>";
  result += "\r<div style=\"display:flex; flex-direction:row; justify-content:flex-end;\">";
  result += "\r<a href=\"/\" style=\"text-decoration:none; margin-top:20px; border:1px solid #428BCA; border-radius:4px; padding:5px 15px 5px 15px; font-size:0.9em; color:#428BCA; background-color:#FFFFFF; cursor:pointer;\">Pick another URL</a>";
  result += "\r</div>";
  result += "\r</div>";
  result += "\r</div>";
  result += "\r</div>";
  result += "\r</body>";
  result += "\r</html>";
  
  server.send(200, "text/html", result);
}
