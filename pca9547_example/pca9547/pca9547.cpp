#include "pca9547.h"

PCA9547::PCA9547() :
  i2c_address_(BASE_I2C_ADDRESS)
{
/// Nothing else to do!
}



PCA9547::PCA9547(uint8_t default_address) :
  i2c_address_(default_address),
  bus_channel_(MIN_INVALID_BUS_ADDRESS)
{
/// Set a valid channel if the input was out of range.
  if (default_address < BASE_I2C_ADDRESS)
    i2c_address_ = BASE_I2C_ADDRESS;

  if (default_address >= BASE_I2C_ADDRESS + NUM_POSSIBLE_ADDRESSES)
    i2c_address_ = BASE_I2C_ADDRESS;
}



PCA9547::~PCA9547()
{
/// Nothing to do!
}



/// It would be nice if this fn returned an error code. We need to use the
/// i2c_t3 lib for that feature.
void PCA9547::setBusChannel(uint8_t channel)
{
/// Do nothing if the channel is already set.
  if (channel == bus_channel_)
    return;

/// Do nothing if desired bus channel is out of range.
  if (channel >= NUM_POSSIBLE_ADDRESSES)
    return;

  Wire.beginTransmission(i2c_address_);
  Wire.write(channel);
  Wire.endTransmission();
}
