#include "prototypes.h"

AudioGeneratorMP3 *mp3;
AudioFileSourceHTTPStream *file;
AudioFileSourceBuffer *buff;
AudioOutputI2S *out;

void playSong(String fileUrl)
{  
  file = new AudioFileSourceHTTPStream(fileUrl.c_str());
  
  buff = new AudioFileSourceBuffer(file, 8 * 4096);
  out = new AudioOutputI2S();
  mp3 = new AudioGeneratorMP3();

  out->SetGain(1.0);
  
  mp3->begin(buff, out);
}

void loopSong()
{  
  if(mp3)
  {
    if(mp3->isRunning())
    {
      if(!mp3->loop()) mp3->stop();
    }
    
    else
    {
      Serial.printf("MP3 done\n");
    }
  }
}
