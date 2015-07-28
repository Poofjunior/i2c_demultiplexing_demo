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
bool initBMA180();
int16_t getAccelZ();
void i2c_read(uint8_t device_address, uint8_t starting_mem_address,
              uint8_t num_bytes, uint8_t* data);


void setup()
{
  pinMode(Pinouts::BINARY_SELECT_0, OUTPUT);
  pinMode(Pinouts::BINARY_SELECT_1, OUTPUT);
  pinMode(Pinouts::BINARY_SELECT_2, OUTPUT);

  Serial.begin(115200); /// baud rate is irrelevant for Teensy USB Serial.
  delay(2000);
  Serial.println("I2C SCL Demultiplexing Demo");

  Wire.begin();
  for (uint8_t bma180_index = 0; bma180_index < NUM_BMA180S; ++bma180_index)
  {
    selectDevice(bma180_index);
    Serial.print("Initializing device ");
    Serial.println(bma180_index);
    if (!initBMA180())
    {
      Serial.print("Error: BMA180 ");
      Serial.print(bma180_index);
      Serial.println(" not responding!");
      /// Do nothing.
      while(1);
    }
  }
}


void loop()
{
  delay(50);
  int16_t raw_accel_z;
  for (uint8_t bma180_index = 0; bma180_index < NUM_BMA180S; ++bma180_index)
  {
    selectDevice(bma180_index);
    raw_accel_z = getAccelZ();
    Serial.print("BMA180 number ");
    Serial.print(bma180_index);
    Serial.print(" | ");
    Serial.print("raw accel_z: ");
    Serial.println(raw_accel_z);
  }
  Serial.println();
}

void selectDevice(uint8_t demultiplexer_channel)
{
  if (demultiplexer_channel > NUM_CHANNELS)
  {
    Serial.println("Error: channel selection out of range.");
    return;
  }

  digitalWrite(Pinouts::BINARY_SELECT_0, demultiplexer_channel & 0x01);
  digitalWrite(Pinouts::BINARY_SELECT_1, demultiplexer_channel & 0x02);
  digitalWrite(Pinouts::BINARY_SELECT_2, demultiplexer_channel & 0x04);
}

bool initBMA180()
{
  uint8_t retreived_id;
  i2c_read(BMA180::I2C_ADDRESS, BMA180::ID, 1, &retreived_id);
  if (retreived_id != BMA180::ID_VAL)
    return false;
  return true;
}

int16_t getAccelZ()
{
  uint8_t num_bytes = 2;
  uint8_t z_data[num_bytes];
  int16_t z_measurement;

  i2c_read(BMA180::I2C_ADDRESS, BMA180::ACCZLSB, num_bytes, z_data);

  /// Unpack signed z data from consecutive registers.
  z_measurement = (int16_t)z_data[0] + (((int16_t)z_data[1]) << 8);
  z_measurement >>= 2;
  return z_measurement;
}

void i2c_read(uint8_t device_address, uint8_t starting_mem_address,
              uint8_t num_bytes, uint8_t* data)
{
/// Format is <START> <WRITE> <DEVICE_ADDRESS> <MEM_ADDRESS> <STOP>;
///           <REP START> <DATA_0> ... <DATA_N> <STOP>;
  Wire.beginTransmission(device_address);
  Wire.write(starting_mem_address);
  Wire.endTransmission();

  Wire.requestFrom(device_address, num_bytes);
  for (uint8_t byte_index = 0; byte_index < num_bytes; ++byte_index)
  {
    data[byte_index] = Wire.read();
  }
}
