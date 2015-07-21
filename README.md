I2C Demultiplexer Demo
======================

This demo implements I2C clock-demultiplexing to communicate with multiple
i2c devices with the same address on a single I2C bus.

### Pros
With an additional piece of hardware (the
[74AC11138](http://www.ti.com/lit/ds/symlink/74ac11138.pdf)) and only three
additional GPIO pins, this hack enables a microcontroller to communicate with
up to eight additional i2c slaves with identical device addresses.

### Drawbacks
Both the SCL and the SDA lines on the I2C bus are inherently bidirectional.
By inserting a demultiplexer between the master's SCL pin and the slaves' SCL
pins, we sacrifice this bidirectionality on the SCL line. Luckily, I2C slaves
only tug on the SCL line if they implement "clock-stretching," a somewhat
uncommon feature among I2C slave devices.

## Pinouts
### 74AC11138 Pinouts
| Pin  | Type   | Connected to...        |
|------|--------|------------------------|
| VCC  | PWR    | Teensy 3.3V            |
| GND  | GND    | GND                    |
| A    | INPUT  | Teensy BINARY_SELECT_0 |
| B    | INPUT  | Teensy BINARY_SELECT_1 |
| C    | INPUT  | Teensy BINARY_SELECT_2 |
| G1   | INPUT  | VCC                    |
| ~G2A | INPUT  | GND                    |
| ~G2B | INPUT  | Teensy SCL             |
| Y0   | OUTPUT | BMA180 0 SCL           |
| Y1   | OUTPUT | BMA180 1 SCL           |
| Y2   | INPUT  | BMA180 2 SCL           |

### BMA180 (0, 1, 2) Pinouts


### Teensy 3.x Pinouts
Note: Names are used here. Pinout numbering is located in **pinouts.hpp**.
| Pin            | Type   | Connected to...            |
|----------------|--------|----------------------------|
| 3.3V           | PWR    | BMA180s and 74AC11138  VCCs|
| GND            | GND    | BMA180s and 74AC11138  GND |
|BINARY_SELECT_0 | OUTPUT | 74AC11138 pin A            |
|BINARY_SELECT_1 | OUTPUT | 74AC11138 pin B            |
|BINARY_SELECT_2 | OUTPUT | 74AC11138 pin C            |
|SDA             | OUTPUT | BMA180 SCLs                |
|SCL             | IN-OUT | 74AC11138 pin ~G2B |

## Compiling this Code

## Running this Code
