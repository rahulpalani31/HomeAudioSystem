#include <Wire.h>
#include "fix_fft.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR 0x3C
#define audioIn A0

const int FFT_SIZE = 256; // Number of samples
const int SAMPLING_FREQ = 20000; // 20 kHz
const int MAX_FREQ = SAMPLING_FREQ / 2; // 10 kHz
const int FREQ_BINS = FFT_SIZE / 2; // 128 bins
const int BIN_WIDTH = MAX_FREQ / FREQ_BINS; // 78.125 Hz per bin

// Frequency Bands
const int BASS_START = 100;
const int BASS_END = 300;
const int MIDRANGE_START = 300;
const int MIDRANGE_END = 4000;
const int TREBLE_START = 4000;
const int TREBLE_END = 10000;

// Frequency Bin Indices
const int BASS_START_BIN = BASS_START / BIN_WIDTH; // 1
const int BASS_END_BIN = BASS_END / BIN_WIDTH; // 3
const int MIDRANGE_START_BIN = MIDRANGE_START / BIN_WIDTH; // 3
const int MIDRANGE_END_BIN = MIDRANGE_END / BIN_WIDTH; // 51
const int TREBLE_START_BIN = TREBLE_START / BIN_WIDTH; // 51
const int TREBLE_END_BIN = TREBLE_END / BIN_WIDTH; // 127

Adafruit_SSD1306 display(128, 64, &Wire, -1);
char real_values[FFT_SIZE], imaginary_values[FFT_SIZE];

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  analogReference(DEFAULT);
};

void loop() {
  // Sample audio signal
  for (int i = 0; i < FFT_SIZE; i++) {
    int sample = analogRead(audioIn);
    real_values[i] = sample / 4 - 128;
    imaginary_values[i] = 0;
  }
  
  // Perform FFT
  fix_fft(real_values, imaginary_values, 7, 0);
  
  // Clear display
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Audio Spectrum");
  
  // Plot frequency spectrum
  for (int i = 0; i < FREQ_BINS; i++) {
    int magnitude = sqrt(real_values[i] * real_values[i] + imaginary_values[i] * imaginary_values[i]);
    int barHeight = map(magnitude, 0, 128, 0, display.height() - 10);
    display.fillRect(i * 2, display.height() - barHeight, 2, barHeight, WHITE);
  }
  
  // Update display
  display.display();
}
