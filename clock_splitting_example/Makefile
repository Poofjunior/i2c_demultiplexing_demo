# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile
# WARNING: Trailing whitespace will cause options to be read incorrectly.

# My target was a teensy3. You may need to change this option to the more
# common teensy31
BOARD_TAG    = teensy3
#BOARD_TAG    = teensy31

# Additional user-defined libraries may be added to this list
ARDUINO_LIBS += Wire

# Default user-defined libraries directory
USER_LIB_PATH += ../

# Teensy explicitly requires Arduino 1.0.x as of Nov 2014
# ARDUINO_DIR should be defined in your Makefile. Otherwise, you may
# define it here.

# teensy3 and teensy31 explicitly require their own Makefile.
include $(ARDMK_DIR)/Teensy.mk


