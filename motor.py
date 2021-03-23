#!/usr/bin/python3

import pyfirmata
from tkinter import *


def analog_pin_to_digital(pin_num): return pin_num + 14


schema = {
    # Use all analog pins: A0-A5(14-19). if do not use all change the number 20
    'digital': tuple(x for x in range(20)),
    # Analog pins has been used as digital ones
    'analog': tuple(x for x in range(5)),
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
analog3 = board.get_pin('d:9:o')
board.digital[analog_pin_to_digital(0)].mode = pyfirmata.OUTPUT  # A0
valuebool = True


def move_servo(a):
    global valuebool
    a = int(a)/255
    # print(a)
    valuebool = not valuebool
    print(valuebool)
    # pin9.write(a)
    # analog3.write(valuebool)
    board.digital[analog_pin_to_digital(0)].write(valuebool)


    # board.analog[2].write(a)
    # print(board.analog[2].read())


# set up GUI
root = Tk()

# draw a nice big slider for servo position
scale = Scale(root,
              command=move_servo,
              to=255,
              orient=HORIZONTAL,
              length=400,
              label='Angle')
scale.pack(anchor=CENTER)

# run Tk event loop
root.mainloop()

board.exit()
