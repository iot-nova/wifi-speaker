#ifndef prototypes
#define prototypes

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Arduino.h>

#include <ESP8266Spiram.h>

#include <AudioFileSource.h>
#include <AudioFileSourceBuffer.h>
#include <AudioFileSourceFS.h>
#include <AudioFileSourceHTTPStream.h>
#include <AudioFileSourceICYStream.h>
#include <AudioFileSourceID3.h>
#include <AudioFileSourcePROGMEM.h>
#include <AudioFileSourceSPIFFS.h>
#include <AudioFileSourceSPIRAMBuffer.h>
#include <AudioFileSourceSTDIO.h>
#include <AudioFileStream.h>
#include <AudioGenerator.h>
#include <AudioGeneratorAAC.h>
#include <AudioGeneratorFLAC.h>
#include <AudioGeneratorMIDI.h>
#include <AudioGeneratorMOD.h>
#include <AudioGeneratorMP3.h>
#include <AudioGeneratorMP3a.h>
#include <AudioGeneratorRTTTL.h>
#include <AudioGeneratorWAV.h>
#include <AudioOutput.h>
#include <AudioOutputBuffer.h>
#include <AudioOutputFilterDecimate.h>
#include <AudioOutputI2S.h>
#include <AudioOutputI2SNoDAC.h>
#include <AudioOutputMixer.h>
#include <AudioOutputNull.h>
#include <AudioOutputSerialWAV.h>
#include <AudioOutputSPIFFSWAV.h>
#include <AudioOutputSTDIO.h>
#include <AudioStatus.h>


String webServerDisplayForm();
String webServerHandleURLForm();

void playSong(String);

#endif
