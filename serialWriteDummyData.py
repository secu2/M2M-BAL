import os, pty, serial, time
from random import randint
master, slave = pty.openpty()
ptyName = os.ttyname(slave)
ser = serial.Serial(ptyName)
print("Ce programme écrit régulièrement une valeur comprise entre 4000 et 10000 dans le port série "+ ptyName + ".")

precVal = randint(5000,10000)
while True:
    if randint(0,3) == 0:
        precVal = randint(5000,10000)
    ser.write(bytes(precVal))
    print(ptyName+"-->"+str(precVal))
    time.sleep(2)

