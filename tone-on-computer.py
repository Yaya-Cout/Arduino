"""Play Arduino sound on computer."""
import pysine
import serial
import time

speed = 9600
port = "/dev/ttyACM0"
with serial.Serial(port, speed, timeout=10, writeTimeout=10) as port_serie:
    if port_serie.isOpen():
        while True:
            ligne = port_serie.readline()
            ligne = str(ligne)
            ligne = ligne.replace("b'", "", 1)
            ligne = ligne.replace("'", "")
            ligne = ligne.replace("\\n", "")
            ligne = ligne.replace("\\r", "")
            if ligne != "":
                print(ligne)
                try:
                    ligne = float(ligne)
                except ValueError:
                    continue

                pysine.sine(frequency=ligne, duration=1.0)
                print(time.time())
