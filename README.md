TFT_ILI9225_SPI
==============

**v1.3.8, released 2018-08-09, Fix error for set backlite brightness with esp8266***

now you can set the backlite brightness with arduino and esp8266

because arduino using 8-bit for PWM, so is differnt from esp8266 (10-bit PWM).

for arduino: brightness is 0-255,

for ESP8266: brightness is 0-1023.


**v1.3.7, released 2018-03-18, Fix compilation error with esp8266 v2.4.1 package**

**v1.3.6, released 2018-03-01, Add high speed color drawBitmap function** Credit: [LAK132](https://github.com/LAK132)

This library is forked from Nkawu/TFT_22_ILI9225, the library suitable for ILI9225 TFT LCD Modules with arduino and ESP8266.

**To install the library:**

* Click the **Download ZIP** button on the right to download **TFT_ILI9225_SPI.zip**
* Extract the ZIP file to the library folder your *arduinosketchfolder*/libraries/ folder. You may need to create the libraries subfolder if it's your first library.
* Rename the uncompressed folder from **TFT_ILI9225_SPI-master** to **TFT_ILI9225_SPI**
* Restart the Arduino IDE

Look at the included "Basic_Demo" example sketch for sample code and the Wiki for documentation.
