"""
 Copyright (c) 2020 Alan Yorinks All rights reserved.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE
 Version 3 as published by the Free Software Foundation; either
 or (at your option) any later version.
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU AFFERO GENERAL PUBLIC LICENSE
 along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
"""

import time
import sys
from pymata4 import pymata4

"""
Setup a pin for digital input and monitor its changes
Both polling and callback are being used in this example.
"""

# Setup a pin for analog input and monitor its changes
DIGITAL_PIN = 12  # arduino pin number
POLL_TIME = 5  # number of seconds between polls

# Callback data indices
# Callback data indices
CB_PIN_MODE = 0
CB_PIN = 1
CB_VALUE = 2
CB_TIME = 3


def the_callback(data):
    """
    A callback function to report data changes.
    This will print the pin number, its reported value and
    the date and time when the change occurred

    :param data: [pin, current reported value, pin_mode, timestamp]
    """
    date = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(data[CB_TIME]))
    print(f'Pin: {data[CB_PIN]} Value: {data[CB_VALUE]} Time Stamp: {date}')


def digital_in(my_board, pin):
    """
     This function establishes the pin as a
     digital input. Any changes on this pin will
     be reported through the call back function.

     :param my_board: a pymata4 instance
     :param pin: Arduino pin number
     """

    # set the pin mode
    for i in range(2, 12):
        my_board.set_pin_mode_digital_input(i, callback=the_callback)
    my_board.set_pin_mode_digital_output(13)
    my_board.set_pin_mode_sonar(4, 5)
    print(my_board.sonar_read(5))
    # on = False
    # while True:
    #     my_board.digital_write(13, int(on))
    #     on = not on
    #     time.sleep(.1)
    while True:
        print(my_board.sonar_read(5))
        time.sleep(1)


board = pymata4.Pymata4()

try:
    digital_in(board, DIGITAL_PIN)
except KeyboardInterrupt:
    board.shutdown()
    sys.exit(0)
