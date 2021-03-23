import pyfirmata
import time
from datetime import datetime
board = pyfirmata.Arduino('/dev/ttyACM0')


start = 0
end = 0

trigpin = board.get_pin('d:5:o')
echopin = board.get_pin('d:4:o')

trigpin.write(0)
time.sleep(5)

while True:
    trigpin.write(1)
    time.sleep(3)
    trigpin.write(0)

    while echopin.read() == 0:
        start = datetime.now().microsecond
    while echopin.read() == 1:
        end = datetime.now().microsecond

    print((end - start) / 58.0)
    print(start, end)
    print(datetime.now().microsecond)
    # time.sleep(1)

board.exit()
