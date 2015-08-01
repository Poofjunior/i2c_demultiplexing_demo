#ifndef PCA9547_H
#define PCA9547_H
#include <stdint.h>
#include <Arduino.h>
#include <Wire.h>

class PCA9547{
public:
/**
 * \brief set the default i2c_channel to the minimum value and set the
 *        bus_address to an invalid value such that the first call to
 *        \fn setBusChannel forces an i2c write.
 * \details Can't return error codes in the constructor, so setting the
 *          default i2c bus channel is done in the \fn init.
 */
  PCA9547();

/**
 * \brief set the default i2c address to the desired value (or default), and
 *        set the bus_address to an invalid value such that the first call to
 *        \fn setBusChannel forces an i2c write.
 * \details Can't return error codes in the constructor, so setting the
 *          default i2c bus channel is done in the \fn init.
 */
  PCA9547(uint8_t default_address);

/**
 * \brief destructor. does nothing.
 */
  ~PCA9547();

/**
 * \brief set the default i2c bus channel to zero.
 * \return nonzero error code if we can't talk to the pca9547 on the i2c bus.
 *         zero otherwise.
 */
  uint8_t init();

/**
 * \brief change the i2c bus channel to the desired value (0 through 7)
 * \return nothing, but it would be nice to return an error code if the
 *         i2c functions time out. (See the i2c_t3 library for Teensy3.1
 *         for a possible implementation)
 */
  void setBusChannel(uint8_t channel);

static const uint8_t BASE_I2C_ADDRESS = 0x70;
static const uint8_t NUM_POSSIBLE_ADDRESSES = 8;

static const uint8_t MIN_INVALID_BUS_ADDRESS = 8;

private:
  uint8_t i2c_address_;
  uint8_t bus_channel_;
};
#endif // PCA9547_H
