# LPC2129 Bluetooth LED Control Project

## Description:
This project demonstrates how to control an LED using the **LPC2129 microcontroller** and an **HC-05 Bluetooth module**. The system receives Bluetooth commands from a smartphone to turn an LED on or off via UART communication. 

### Features:
- **LPC2129** communicates with **HC-05** via UART (TXD0, RXD0).
- **Bluetooth terminal** on a smartphone sends commands to control the LED.
- Command `'1'` turns **ON** the LED.
- Command `'0'` turns **OFF** the LED.

### Hardware Required:
1. **LPC2129** development board.
2. **HC-05 Bluetooth module**.
3. **LED** connected to **P1.16** of LPC2129 (or any other GPIO pin).
4. **Resistor (220 ohms)** for the LED.
5. **Android smartphone** with a Bluetooth terminal app (e.g., Serial Bluetooth Terminal).

### Circuit Connections:
| HC-05 Pin   | LPC2129 Pin  |
|-------------|--------------|
| VCC         | 3.3V or 5V   |
| GND         | GND          |
| TXD         | P0.1 (RXD0)  |
| RXD         | P0.0 (TXD0)  |

### Steps to Run:
1. Connect the **HC-05 Bluetooth module** to the **LPC2129** using the connections mentioned above.
2. Load the code onto the **LPC2129** using Keil uVision.
3. Open the **Bluetooth Serial Terminal** app on your Android device.
4. Pair and connect to the **HC-05** module.
5. Send command `'1'` to turn ON the LED and `'0'` to turn OFF the LED.

### Files:
1. **pin_cfg.c**: Configures the pins of the LPC2129 (UART and GPIO for LED control).
2. **pin_cfg.h**: Header file for pin configuration functions.
3. **pin_cfg_defines.h**: Defines the pin functions and constants.
4. **bluetooth_led_control.c**: Main application code to initialize UART and control the LED based on received commands.
5. **types.h**: Defines the basic data types (`u8`, `u16`, `u32`) for the project.
6. **delay.h**: Provides a basic delay function (`delay_ms()`) for the project.

### Code Explanation:
1. **UART Initialization**: The `UART0_Init()` function initializes UART0 for communication between the LPC2129 and HC-05.
2. **LED Control**: Based on the commands received from the Bluetooth terminal, the `LED_PIN` is toggled on or off.
3. **Bluetooth Communication**: Commands are received using `UART0_ReceiveChar()` and executed accordingly to turn the LED ON or OFF.

### Requirements:
- Keil uVision IDE or any other tool compatible with LPC2129.
- Basic knowledge of **UART communication**.
- Bluetooth terminal app for your Android phone.

### License:
This project is open-source. Feel free to use and modify it as needed.

