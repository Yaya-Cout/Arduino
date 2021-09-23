#!/usr/bin/python3
# -*- coding: utf-8 -*-
# move a servo from a Tk slider - scruss 2012-10-28

import pyfirmata
from tkinter import *

# don't forget to change the serial port to suit
board = pyfirmata.Arduino('/dev/ttyACM0')

# start an iterator thread so
# serial buffer doesn't overflow
iter8 = pyfirmata.util.Iterator(board)
iter8.start()

# set up pin D9 as Servo Output
pin9 = board.get_pin('d:3:s')


def move_servo(a):
    pin9.write(180-int(a))


# set up GUI
root = Tk()

# draw a nice big slider for servo position
scale = Scale(root,
              command=move_servo,
              to=181,
              orient=HORIZONTAL,
              length=400,
              label='Angle')
scale.pack(anchor=CENTER)

# run Tk event loop
root.mainloop()

board.exit()
