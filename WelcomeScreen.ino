#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 

#define SCREEN_WIDTH 128 ]
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 

void setup() { 
  // Initialize the OLED display 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed"); for (;;); // Error Handling so loop doesn’t go on forever
  } 

  display.clearDisplay(); 
  display.setTextColor(WHITE); 
  display.setTextSize(2); 

  display.setCursor((SCREEN_WIDTH - 7 * 12) / 2, (SCREEN_HEIGHT - 16) / 2); 
  display.println("Welcome!"); 
  display.display(); 
  delay(5000); 

  display.clearDisplay(); 
  display.setTextColor(WHITE); 
  display.setTextSize(1); 

  display.setCursor(0, 0); 
  display.println("Home Audio"); 
  display.setCursor(0, 10); 
  display.println("System Project"); 

  display.setCursor(0, 30); 
  display.println("By: Rahul Palani"); 
  display.setCursor(0, 40); 
  display.println("and Cohn Betz"); 

  display.display(); 
} 

void loop() { 
}
