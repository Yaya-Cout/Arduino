#!/usr/bin/python3

import pyfirmata
import time
from datetime import datetime


def analog_pin_to_digital(pin_num): return pin_num + 14


def delayMicroseconds(microseconds): time.sleep(microseconds/1000000.0)


def pulseIn(pin, value):
    timestart = datetime.now().microsecond
    print(pin)
    while not board.analog[pin].read() == value:
        print(board.analog[pin].read())
    return datetime.now().microsecond - timestart


def Distance_test() -> int:
    board.digital[Trig].write(False)
    delayMicroseconds(2)
    board.digital[Trig].write(True)
    delayMicroseconds(10)
    board.digital[Trig].write(False)
    fdistance = pulseIn(Echo, True)
    fdistance = fdistance / 58
    return fdistance


digital = list(x for x in range(20))
del digital[18]
digital = tuple(digital)
analog = tuple(x for x in range(5))
schema = {
    # Use all analog pins: A0-A5(14-19). if do not use all change the number 20
    'digital': digital,
    # Analog pins has been used as digital ones
    'analog': analog,
    'pwm': (3, 5, 6, 9, 10, 11),
    'use_ports': True,
    'disabled': (0, 1)  # Rx, Tx, Crystal
}


# don't forget to change the serial port to suit
# board = pyfirmata.Arduino('/dev/ttyACM2')
board = pyfirmata.Board("/dev/ttyACM1", layout=schema)
# start an iterator thread so
# serial buffer doesn't overflow
iter8 = pyfirmata.util.Iterator(board)
iter8.start()

# set up pin D3 as Servo Output
# pin9 = board.get_pin('d:3:s')
analog3 = board.get_pin('d:14:o')
Echo = 4
Trig = analog_pin_to_digital(5)-1
# Trig = 13
board.analog[Echo].mode = pyfirmata.INPUT  # A4
board.digital[Trig].mode = pyfirmata.OUTPUT  # A5
try:
    print(Distance_test())
except KeyboardInterrupt:
    board.exit()
