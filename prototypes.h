#ifndef prototypes
#define prototypes

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Arduino.h>

#include <ESP8266Spiram.h>

#include <AudioFileSourceICYStream.h>
#include <AudioFileSourceBuffer.h>
#include <AudioGeneratorMP3.h>
#include <AudioOutputI2S.h>

void webServerDisplayForm();
void webServerHandleURLForm();
void playSong(String);

#endif
