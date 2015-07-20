/**
  \author Joshua Vasquez <joshuavasquez@hackaday.com>
  \date July 19, 2015
  \pre A Teensy 3.1 and the corresponding circuit are required to run
       this demo.
  \details This software demo is targeted for the Teensy 3.1 and may be
           compiled with the Arduino Makefile.
  \license The MIT License
**/
#include <Wire.h>
#include "pinouts.hpp"
#include "bma180_address_list.h"

/// constants
const uint8_t NUM_CHANNELS = 3;
const uint8_t NUM_BMA180S = NUM_CHANNELS;

/// Function Prototypes
void selectDevice(uint8_t demultiplexer_channel);
void initBMA180();
int16_t getAccelZ();

void setup()
{
  Serial.begin(115200); /// baud rate is irrelevant for Teensy USB Serial.

  Wire.begin();
  for (uint8_t bma180_index = 0; bma180_index < NUM_BMA180S; ++bma180_index)
  {
    selectDevice(bma180_index);
    initBMA180();
  }
}


void loop()
{
  int16_t raw_accel_z;
  for (uint8_t bma180_index = 0; bma180_index < NUM_BMA180S; ++bma180_index)
  {
    selectDevice(bma180_index);
    raw_accel_z = getAccelZ();
    Serial.println("BMA180 device ");
    Serial.print("raw accel_z: ");
    Serial.println(raw_accel_z);
  }
  Serial.println();
}

void selectDevice(uint8_t demultiplexer_channel)
{
  if (demultiplexer_channel > NUM_CHANNELS)
    return;

  digitalWrite(Pinouts::BINARY_SELECT_0, demultiplexer_channel & 0x01);
  digitalWrite(Pinouts::BINARY_SELECT_1, demultiplexer_channel & 0x02);
  digitalWrite(Pinouts::BINARY_SELECT_2, demultiplexer_channel & 0x04);
}

int16_t getAccelZ()
{
  return 0;
}
