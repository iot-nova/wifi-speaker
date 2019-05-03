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
In our case, we used a **Wemos D1 Mini** as our microcontroller with an **Analog I2S DAC**.
Here are the pins mapping between our microcontroller and our I2S DAC: 

Wemos D1 Mini (Pro) | I2S DAC
------------------- | -------
5V/3.3V\* | Vcc
GND | GND
RX | Data
D8 | BCLK
D4 | LRCLK/WCK

\*: In our case, only the connection between the 5V and the VCC worked. The 3.3V did not work, but it might work in your case depending on your hardware configuration.


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
