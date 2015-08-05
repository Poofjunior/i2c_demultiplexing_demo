PCA9547 Demo
======================

This demo uses the PCA9547 to communicate with multiple
i2c devices with the same address on a single host I2C bus.

### Pros


## Pinouts
### PCA9547 Pinouts
| Pin    | Type   | Connected to...        |
|--------|--------|------------------------|
| VCC    | PWR    | Teensy 3.3V          |
| GND    | GND    | GND                  |
| A0     | INPUT  | GND                  |
| A1     | INPUT  | GND                  |
| A2     | INPUT  | GND                  |
| ~RESET | INPUT  | VCC                  |
| SD0    | IN-OUT | BMA180 0 SDA         |
| SC0    | IN-OUT | BMA180 0 SCL         |
| SD1    | IN-OUT | BMA180 1 SDA         |
| SC1    | IN-OUT | BMA180 1 SCL         |
| SD2    | IN-OUT | BMA180 2 SDA         |
| SC2    | IN-OUT | BMA180 2 SCL         |

### Teensy 3.x Pinouts
| Pin             | Type   | Connected to...             |
|-----------------|--------|-----------------------------|
| 3.3V            | PWR    | BMA180s and PCA9547 VCCs    |
| GND             | GND    | BMA180s and PCA9547 GND     |
| SDA             | IN-OUT | PCA9547 SCL                 |
| SCL             | IN-OUT | PCA9547 SDA                 |

## Compiling this Code

This code can be compiled with The [Arduino Makefile](https://github.com/sudar/Arduino-Makefile)

## Running this Code
After uploading, view the Serial port window for incoming data from the z-axis
of each sensor.
