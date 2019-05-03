# Wifi-Speaker

## GROUP MEMBERS
N : Nicolas CORNU

O : Olivier LEFEBVRE

V : Vincent VALVAS

A : Alexandre FELIX


## DESCRIPTION
Configure a web server on your microcontroller to listen to music through your speakers via the wifi network.


## HARDWARE REQUIREMENTS
Product | Quantity | Price | Informations
------- | -------- | ----- | ------------
Micro USB cable | 1 | ~3.00€ | N/A
**ESP8266 compatible Microcontroller** | 1 | 2.00€ | N/A
I2S DAC | 1 | From ~15.00€ | Any basic I2S DAC with a jack output is enough.
Audio output jack-compatible (speakers, headphones, etc.) | 1 | ?.??€ | N/A

You can use a DAC which would act as an audio interface between your microcontroller and your audio output (speaker, headphones, etc).
In our case, we used a **Wemos D1 Mini** as our microcontroller with an **Analog I2S DAC PCM5102A**.


Here are the pins mapping between our microcontroller and our DAC: 

Wemos D1 Mini (Pro) | I2S DAC
------------------- | -------
5V/3.3V\* | Vcc
GND | GND
RX | Data
D8 | BCLK
D4 | LRCLK/WCK

\*: In our case, only the connection between the 5V and the VCC worked. The 3.3V did not work, but it might work in your case depending on your hardware configuration.

![Visual representation](https://e2e.ti.com/cfs-file/__key/communityserver-discussions-components-files/64/0184.232.jpg)

Our DAC has a jumper which allows us to switch between the "I2S" mode and the "Left Justify" mode. We used the "I2S" mode in order to register an audio output with good quality, but the "Left Justify" mode has heavy noises output alongside the music.
Theses modes are PCM data formats.

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

### ARDUINO LIBRARIES USED
- ESP8266Wifi
- ESP8266Audio - Currently (03/05/2019) not in the library manager but can be found here: https://github.com/earlephilhower/ESP8266Audio
- ESP8266WebServer


