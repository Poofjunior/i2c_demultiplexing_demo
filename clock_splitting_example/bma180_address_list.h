#ifndef BMA180_ADDRESS_LIST_H
#define BMA180_ADDRESS_LIST_H

namespace BMA180
{
  static const uint8_t I2C_ADDRESS = 0x40;

  static const uint8_t ID = 0x00;
  static const uint8_t ID_VAL = 0x03;


  static const uint8_t ACCXLSB = 0x02;
  static const uint8_t ACCXMSB = 0x03;
  static const uint8_t ACCYLSB = 0x04;
  static const uint8_t ACCYMSB = 0x05;
  static const uint8_t ACCZLSB = 0x06;
  static const uint8_t ACCZMSB = 0x07;

  static const uint8_t TEMPERATURE = 0x08;

  static const uint8_t STATREG1 = 0x09;
  static const uint8_t STATREG2 = 0x0A;
  static const uint8_t STATREG3 = 0x0B;
  static const uint8_t STATREG4 = 0x0C;
  static const uint8_t CTRLREG0  = 0x0D;
  static const uint8_t CTRLREG1  = 0x0E;
  static const uint8_t CTRLREG2  = 0x0F;

  static const uint8_t BWTCS = 0x20;

  static const uint8_t CTRLREG3 = 0x21;

  static const uint8_t HILOWINFO  = 0x25;
  static const uint8_t LOWDUR  = 0x26;

  static const uint8_t LOWTHR  = 0x29;

  static const uint8_t OLSB1 = 0x35;

}
#endif // BMA180_ADDRESS_LIST_H
