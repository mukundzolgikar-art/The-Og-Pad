/*
  HAck Pad - XIAO ESP32-C3 BLE Macro Pad
  ---------------------------------------
  Switch mapping from the uploaded PCB:
    SW1 -> XIAO D10 / GPIO10 -> A
    SW2 -> XIAO D9  / GPIO9  -> B
    SW3 -> XIAO D8  / GPIO8  -> C

  The ESP32-C3 does not provide USB HID keyboard over its native USB
  interface, so this firmware uses Bluetooth Low Energy (BLE) HID.

  Required Arduino library:
    ESP32C3-BLE-Keyboard (BleKeyboard.h)
    NimBLE-Arduino

  Install the ESP32 board package and select:
    Tools -> Board -> ESP32 Arduino -> XIAO_ESP32C3
*/

#include <Arduino.h>
#include <BleKeyboard.h>

// XIAO ESP32-C3 GPIO numbers for D8, D9 and D10.
constexpr uint8_t SW1_PIN = 10;  // D10
constexpr uint8_t SW2_PIN = 9;   // D9
constexpr uint8_t SW3_PIN = 8;   // D8

BleKeyboard bleKeyboard("HAck Pad", "HAck Club", 100);

struct Button {
  uint8_t pin;
  uint8_t key;
  bool lastState;
};

Button buttons[] = {
  {SW1_PIN, 'a', HIGH},
  {SW2_PIN, 'b', HIGH},
  {SW3_PIN, 'c', HIGH}
};

constexpr uint32_t DEBOUNCE_MS = 25;
uint32_t lastChange[3] = {0, 0, 0};

void setup() {
  Serial.begin(115200);

  for (auto &button : buttons) {
    pinMode(button.pin, INPUT_PULLUP);
    button.lastState = digitalRead(button.pin);
  }

  bleKeyboard.begin();

  Serial.println("HAck Pad started.");
  Serial.println("SW1=D10/GPIO10 -> A");
  Serial.println("SW2=D9/GPIO9   -> B");
  Serial.println("SW3=D8/GPIO8   -> C");
}

void loop() {
  const uint32_t now = millis();

  for (size_t i = 0; i < 3; ++i) {
    bool currentState = digitalRead(buttons[i].pin);

    if (currentState != buttons[i].lastState &&
        (now - lastChange[i]) >= DEBOUNCE_MS) {

      lastChange[i] = now;
      buttons[i].lastState = currentState;

      // Buttons are wired to GND, so LOW means pressed.
      if (currentState == LOW) {
        Serial.printf("SW%u pressed\n", (unsigned)(i + 1));

        if (bleKeyboard.isConnected()) {
          bleKeyboard.press(buttons[i].key);
        }
      } else {
        Serial.printf("SW%u released\n", (unsigned)(i + 1));

        if (bleKeyboard.isConnected()) {
          bleKeyboard.release(buttons[i].key);
        }
      }
    }
  }

  delay(1);
}
