import RPi.GPIO as GPIO
import time

buzzer_pin = 2

GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer_pin, GPIO.OUT)

GPIO.output(buzzer_pin, False)

