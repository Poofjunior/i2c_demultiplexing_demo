PCA9547 Demo
======================

This demo uses the PCA9547 to communicate with multiple
i2c devices with the same address on a single host I2C bus.

### Pros


## Pinouts
### PCA9547 Pinouts
| Pin  | Type   | Connected to...        |
|------|--------|------------------------|
| VCC  | PWR    | Teensy 3.3V            |
| GND  | GND    | GND                    |

### BMA180 (0, 1, 2) Pinouts

Note: Pinout names are used below. Pinout numbering is located in
 **pinouts.hpp**.
### Teensy 3.x Pinouts
| Pin             | Type   | Connected to...             |
|-----------------|--------|-----------------------------|
| 3.3V            | PWR    | BMA180s and 74AC11138 VCCs  |
| GND             | GND    | BMA180s and 74AC11138 GND   |
| SDA             | OUTPUT | BMA180 SCLs                 |
| SCL             | IN-OUT | 74AC11138 pin ~G2B          |

## Compiling this Code

This code can be compiled with The [Arduino Makefile](https://github.com/sudar/Arduino-Makefile)

## Running this Code
After uploading, view the Serial port window for incoming data from the z-axis
of each sensor.
