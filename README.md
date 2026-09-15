# HAck Pad Firmware

This firmware is for the uploaded HAck Pad PCB using a Seeed XIAO ESP32-C3.

## Switch mapping

| Switch | PCB net | XIAO pin | ESP32-C3 GPIO | Key |
|---|---|---|---:|---|
| SW1 | D10 | D10 | GPIO10 | A |
| SW2 | D9 | D9 | GPIO9 | B |
| SW3 | D8 | D8 | GPIO8 | C |

The PCB file shows SW1 on D10, SW2 on D9 and SW3 on D8.

## Important

The ESP32-C3 cannot act as a native USB HID keyboard through its USB Serial/JTAG interface. This firmware therefore uses **Bluetooth Low Energy (BLE) HID**.

## Arduino IDE setup

1. Install Arduino IDE.
2. Install the Espressif ESP32 board package.
3. Select `XIAO_ESP32C3`.
4. Install the `ESP32C3-BLE-Keyboard` library so that `BleKeyboard.h` is available.
5. Install `NimBLE-Arduino` if the selected BLE keyboard library requires it.
6. Open `HAck_Pad_BLE.ino`.
7. Select the XIAO ESP32-C3 COM port.
8. Upload.
9. On your computer, open Bluetooth settings and pair with **HAck Pad**.
10. Press the three switches to send A, B and C.

The firmware uses `INPUT_PULLUP`, so each switch is treated as active-low.
