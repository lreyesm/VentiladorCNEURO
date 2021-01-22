import RPi.GPIO as GPIO
import time

buzzer_pin = 2
pwr_pin = 3


GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer_pin, GPIO.OUT)
GPIO.setup(pwr_pin, GPIO.OUT)

GPIO.output(buzzer_pin, False)
GPIO.output(pwr_pin, False)




