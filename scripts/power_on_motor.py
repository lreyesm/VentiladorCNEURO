import RPi.GPIO as GPIO
import time

pwr_pin = 3

GPIO.setmode(GPIO.BCM)
GPIO.setup(pwr_pin, GPIO.OUT)

GPIO.output(pwr_pin, False)




