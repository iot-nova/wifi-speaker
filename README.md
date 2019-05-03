# Wifi-Speaker

## GROUP MEMBERS
N : Nicolas CORNU

O : Olivier LEFEBVRE

V : Vincent VALVAS

A : Alexandre FELIX


## DESCRIPTION
Wifi-Speaker lets you upload a webserver on your microcontroller in order to play musics from the web via HTTP streaming.
Basically, Wifi-Speaker allows you to chose any MP3 music to play on a RCA/Jack audio output device from your PC without needing a cable connection.


## HARDWARE REQUIREMENTS
Product | Quantity | Price | Informations
------- | -------- | ----- | ------------
Micro USB cable | 1 | ~3.00€ | N/A
**ESP8266 compatible Microcontroller** | 1 | 2.00€ | N/A
I2S DAC | 1 | From ~15.00€ | Any basic I2S DAC with a RCA output is fine.
RCA output device | 1 | ?.??€ | You can use a jack output device but with an RCA to Jack adapter.

You can use a DAC which would act as an audio interface between your microcontroller and your audio output device.
In our case, we used a **Wemos D1 Mini** as our microcontroller with an **Analog I2S DAC PCM5102A** which has an RCA port and therefore a RCA to Jack adapter.


Here are the pins mapping between our microcontroller and our DAC: 

Wemos D1 Mini (Pro) | I2S DAC
------------------- | -------
5V/3.3V\* | Vcc
GND | GND
RX | Data
D8 | BCLK
D4 | LRCLK/WCK

\*: In our case, only the connection between the 5V and the VCC worked. The 3.3V did not work, but it might work in your case depending on your hardware configuration.

![I2S mode visual representation](https://e2e.ti.com/cfs-file/__key/communityserver-discussions-components-files/64/0184.232.jpg)

Our DAC has a jumper which allows us to switch between the "I2S" mode and the "Left Justify" mode. **We used the "I2S" mode** in order to register an audio output with good quality, but the "Left Justify" mode has heavy noises output alongside the music.
Theses modes are PCM data formats.

![Left Justify mode visual representation](https://e2e.ti.com/cfs-file/__key/communityserver-discussions-components-files/64/0535.231.jpg)

For instance, a left-justified result means that bits [15:(16-N)] of the register hold the result, and bits [(15-N):0] are set to zero. If your actual conversion result is 0x123, it would be read as 0x1230 if it was left-justified.

An advantage of left-justified results (on processors that support it) is that you can take just the most-significant byte of the register, giving you 8-bits of precision instead of the native precision. This can be useful if you don't need the extra precision, or have RAM constraints and want to store a large number of samples.


## SOFTWARE REQUIREMENTS
Install the Arduino IDE: https://www.arduino.cc/en/Main/Software

Install this driver if you don't use Linux: https://wiki.wemos.cc/downloads

If you never used ESP8266 with your Arduino IDE you need to follow this procedure: 
https://www.github.com/esp8266/Arduino#installing-with-boards-manager

If you never used the MPU-6050 or OSC in Arduino, use the following keywords in the Library Manager:
- MPU6050
- Open Sound Control (OSC) by Adrian Freed and Yotam Mann

Finally, set the following board options in your Arduino:
- Upload Speed: "115200"
- CPU Frequency: 160 Mhz
- IwIP Variant: "v2 Higher Bandwidth" or "v1.4 Open Source"
- Port: "COM5" or the first entry in the list which is not grayed out/disabled.

Depending on your system on which you connect the microcontroller, you might need to configure your COM port.

On windows, you would have to open the Device manager, then click on "Ports (COM and LPT)", then on the corresponding port that you chose in Arduino right before (e.g.: "COM5").
After that, access to the properties of that port by right clicking on it.
Finally, click on "Port parameters", then change the "Bits per second" value to the corresponding set value before which is "115200".

![Example in french with a screenshot](https://i.imgur.com/xymjNYK.png)

### ARDUINO LIBRARIES USED
- ESP8266Wifi
- ESP8266Audio - Currently (03/05/2019) not in the library manager but can be found here: https://github.com/earlephilhower/ESP8266Audio
- ESP8266WebServer

## HOW TO USE IT?

1 - Upload the sketch to your microcontroller and wait for its completion.

2 - Open the "Serial Monitor" and check the local IP address used by the webserver on the microcontroller.

3 - Copy this IP then paste it in the URL section of your web browser to access it.

4 - You should see a web page where you can enter an URL address **which points directly to the MP3 file** you want to play.

5 - Click on play then a bit for the music to be played because there is a delay at first depending on the size of the music file. Once the music is playing, you should see outputs in the Serial Monitor.


## WARNING

There are two problems that we have not resolve yet:

1 - The delay when first playing the music.

2 - Some hiccups while playing the music which is due to the lack of buffering, but setting the buffering causes the music to be unreadable.
