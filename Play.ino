#include "prototypes.h"

void playSong(String fileUrl)
{      
  file = new AudioFileSourceHTTPStream(fileUrl.c_str());

  Serial.println(fileUrl.c_str());
  
  //buff = new AudioFileSourceBuffer(file, 2048);
  out = new AudioOutputI2S();
  mp3 = new AudioGeneratorMP3();
  
  mp3->begin(file, out);
}
