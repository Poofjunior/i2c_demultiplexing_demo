I2C Demultiplexer Demo
======================

This demo implements I2C clock-demultiplexing to communicate with multiple
i2c devices with the same address on a single I2C bus.

### Pros
With an additional piece of hardware (the
[74AC11138](http://www.ti.com/lit/ds/symlink/74ac11138.pdf) and only three
additional GPIO pins, this hack enables a microcontroller to communicate with
up to eight additional i2c slaves with identical device addresses.

### Drawbacks
Both the SCL and the SDA lines on the I2C bus are inherently bidirectional.
By inserting a demultiplexer between the master's SCL pin and the slaves' SCL
pins, we sacrifice this bidirectionality on the SCL line. Luckily, I2C slaves
only tug on the SCL line if they implement "clock-stretching," a somewhat
uncommon feature among I2C slave devices.

## Compiling this Code

## Running this Code
