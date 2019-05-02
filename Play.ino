#include "prototypes.h"

AudioGeneratorMP3 *mp3;
AudioFileSourceHTTPStream *file;
AudioFileSourceBuffer *buff;
AudioOutputI2SNoDAC *out;

void playSong(String fileUrl)
{
  // Create the HTTP stream normally
  file = new AudioFileSourceHTTPStream("fdvdf");
  
  // Create a buffer using that stream
  buff = new AudioFileSourceBuffer(file, 2048);
  out = new AudioOutputI2SNoDAC();
  mp3 = new AudioGeneratorMP3();
  
  // Pass in the *buffer*, not the *http stream* to enable buffering
  mp3->begin(buff, out);
}
