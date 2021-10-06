import pyautogui as auto
import time
import serial

time.sleep(1)

ard=serial.Serial("COM3",timeout=1,baudrate=9600)

while True:
    cc=str(ard.readline())
    z=cc[2:][:-5]
    if(z=="1"):
        print("yes")
        auto.hotkey('winleft','tab')
        time.sleep(0.3)
        auto.click(800,250)

    if(z=="0"):
        print("back")
        auto.hotkey('winleft', 'tab')
        time.sleep(0.3)
        auto.click(600, 250)



