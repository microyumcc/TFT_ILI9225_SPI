/*
 * Title: Example of microyum ILI9225 TFT modules
 * Author: Microyum
 * Version: 1.0
 * Update: 2018/08/01
 * 
 * please make sure you have install TFT_ILI9225_SPI librariey.
 * TFT_ILI9225_SPI https://github.com/microyumcc/TFT_ILI9225_SPI
 * download the libraries and copy into arduino's library folder.
 * 
 */
#include "TFT_ILI9225_SPI.h"

#ifdef ESP8266
#define TFT_RST D4
#define TFT_RS  D2
#define TFT_CS  D8  // SS
#define TFT_SDI D7  // MOSI
#define TFT_CLK D5  // SCK
#define TFT_LED D1   // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 1023
#else
#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  // SS
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
#define TFT_LED 3   // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 255
#endif

uint8_t TFT_W, TFT_H;

int colorList[6] = {0xFC9F, COLOR_RED, COLOR_ORANGE, COLOR_YELLOW, COLOR_GREENYELLOW, COLOR_OLIVE};

TFT_ILI9225_SPI tft = TFT_ILI9225_SPI(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);

void setup() {
  Serial.begin(9600);
  tft.begin();
  TFT_W = tft.maxX();
  TFT_H = tft.maxY();
}

void loop() {
  testText();
  delay(2000);
  testVertScroll();
  delay(2000);
  testBacklight();
  delay(2000);
  testDrawCircle();
  delay(2000);
  testLine();
  delay(2000);
  testRect();
  delay(2000);
  testTriangle();
  delay(2000);
  testPixel();
  delay(2000);
}

void testText() {
  tft.fillRectangle(0, 0, TFT_W/2-1, TFT_H, COLOR_WHITE);
  tft.fillRectangle(TFT_W/2, 0, TFT_W, TFT_H, COLOR_RED);
  tft.setFont(Terminal6x8);
  tft.drawText(0, 0, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*();:'/.,<>?", COLOR_BLACK);
  tft.setFont(Terminal11x16);
  tft.drawText(0, 40, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*();:'/.,<>?", COLOR_BLUE);
  tft.setFont(Terminal6x8);
  tft.drawText(0, 130, "Text With Background Color", COLOR_WHITE, COLOR_BLACK);
}

void testBacklight() {
  tft.setBacklight(false);
  delay(1000);
  tft.setBacklight(true);
}

void testVertScroll() {
  for (uint16_t i=1; i <= 220; i++) {
    tft.vertScroll(0, 220, i);
    delay(10);
  }
  delay(1000);
  for (uint16_t i=1; i <= 220; i++) {
    tft.vertScroll(0, 220, 0- (int16_t)i);
    delay(10);
  }
}

void testDrawCircle() {
  tft.fillScreen(COLOR_BLACK);
  int centerX = TFT_W/2, centerY = TFT_H/2;
  int radius = TFT_W/4-2;
  for(int i = 0, s = 0; i < 360; i += 4, s += 1) {
    if(s>5) s = 0;
    tft.drawCircle(centerX + radius * cos(i * M_PI / 180), centerY + radius * sin(i * M_PI / 180), radius, colorList[s]);
  }
}

void testLine() {
  tft.fillScreen(COLOR_BLACK);
  int x1=0, y1=0, x2, y2;
  
  for(x2 = 0; x2 < TFT_W; x2 += 6) tft.drawLine(x1, y1, x2, TFT_H, COLOR_CYAN);
  for(x2 = TFT_W; x2 > 0; x2 -=6) tft.drawLine(TFT_W, TFT_H, x2, 0, COLOR_CYAN);
}

void testRect() {
  tft.fillScreen(COLOR_BLACK);
  int m, init_radius = 5;
  m = min(TFT_W, TFT_H);
  for(int i = init_radius, s = 0; i * 2 < m; i += 4, s += 1) {
    tft.drawRectangle(TFT_W/2-i, TFT_H/2-i, (TFT_W/2-i) + (i*2), (TFT_H/2-i) + (i*2), tft.setColor(0, 237, i));
  }
}

void testTriangle() {
  tft.fillScreen(COLOR_BLACK);
  int m, x, y;
  x = TFT_W/2;
  y = TFT_H/2;
  m = min(x, y);
  for(int i = m; i > 0; i -= 5 ) {
    tft.drawTriangle(x, y-i, x-i, y+i, x+i, y+i, tft.setColor(0, 237, i));
  }
}

void testPixel() {
  tft.fillScreen(COLOR_BLACK);
  for (int i=0; i<10000; i++)
  {
    tft.drawPixel(2+random(TFT_W), 2+random(TFT_H), tft.setColor(random(255), random(255), random(255)));
  }
}

